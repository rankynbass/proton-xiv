# parameters:
#   $(1): lowercase package name
#   $(2): uppercase package name
#   $(3): build target <arch>
#   $(4): CROSS/<empty>, cross compile
define create-rules-common
$(2)_$(3)_OBJ := $$(OBJ)/obj-$(1)-$(3)
$(2)_$(3)_DST := $$(OBJ)/dst-$(1)-$(3)
$(2)_$(3)_DEPS := $$(call toupper,$$($(2)_DEPENDS)) $$(call toupper,$$($(2)_$(3)_DEPENDS))

$(2)_$(3)_BINDIR ?= $$($(2)_$(3)_DST)/bin
$(2)_$(3)_LIBDIR ?= $$($(2)_$(3)_DST)/lib
$(2)_$(3)_INCDIR ?= $$($(2)_$(3)_DST)/include

$$(OBJ)/.$(1)-$(3)-configure: $$(shell mkdir -p $$($(2)_$(3)_OBJ))
$$(OBJ)/.$(1)-$(3)-configure: CCACHE_BASEDIR = $$($(2)_SRC)
$$(OBJ)/.$(1)-$(3)-configure: $$(patsubst %,%-$(3)-build,$$($(2)_DEPENDS) $$($(2)_$(3)_DEPENDS))
$$(OBJ)/.$(1)-$(3)-configure: | $$(OBJ)/.$(1)-post-source

$(1)-$(3)-configure: $$(OBJ)/.$(1)-$(3)-configure
.INTERMEDIATE: $(1)-$(3)-configure

all-$(3)-configure $(1)-configure: $(1)-$(3)-configure
.PHONY: all-$(3)-configure $(1)-configure

all-configure: $(1)-configure
.PHONY: all-configure


$$(OBJ)/.$(1)-$(3)-build: CCACHE_BASEDIR = $$($(2)_SRC)
$$(OBJ)/.$(1)-$(3)-build: $$(OBJ)/.$(1)-source
$$(OBJ)/.$(1)-$(3)-build: $$(OBJ)/.$(1)-$(3)-configure

$$(OBJ)/.$(1)-$(3)-post-build: $$(OBJ)/.$(1)-$(3)-build

$(1)-$(3)-build: $$(OBJ)/.$(1)-$(3)-build
.INTERMEDIATE: $(1)-$(3)-build

all-$(3)-build $(1)-build: $(1)-$(3)-build
.PHONY: all-$(3)-build $(1)-build

all-build: $(1)-build
.PHONY: all-build


$$(OBJ)/.$(1)-$(3)-dist: $$(OBJ)/.$(1)-$(3)-build
$$(OBJ)/.$(1)-$(3)-dist: $$(OBJ)/.$(1)-$(3)-post-build

$(2)_$(3)_SOURCE_DATE_EPOCH ?= $$($(3)_SOURCE_DATE_EPOCH)

$$(OBJ)/.$(1)-$(3)-dist:
	@echo ":: installing $(1)-$(3)..." >&2
	if [ -f "$$($(2)_$(3)_OBJ)/compile_commands.json" ]; then \
	    mkdir -p "$$(OBJ)/compile_commands/$(1)-$(3)/"; \
	    sed "s#$$($(2)_SRC)#$$($(2)_ORIGIN)#g" "$$($(2)_$(3)_OBJ)/compile_commands.json" > "$$(OBJ)/compile_commands/$(1)-$(3)/compile_commands.json"; \
	fi
	mkdir -p $$($(2)_$(3)_LIBDIR)/ $$(DST_LIBDIR)/
	cd $$($(2)_$(3)_LIBDIR) && find -type f -printf '$$(DST_LIBDIR)/%h\0' | sort -z | uniq -z | xargs $(--verbose?) -0 -r -P$$(J) mkdir -p
	cd $$($(2)_$(3)_LIBDIR) && find -type l -printf '%p\0$$(DST_LIBDIR)/%p\0' | xargs $(--verbose?) -0 -r -P$$(J) -n2 cp -a
ifneq ($(UNSTRIPPED_BUILD),)
	cd $$($(2)_$(3)_LIBDIR) && find -type f -not '(' -iname '*.pc' -or -iname '*.cmake' -or -iname '*.a' -or -iname '*.la' -or -iname '*.def' -or -iname '*.h' ')' \
	    -printf '--only-keep-debug\0%p\0$$(DST_LIBDIR)/%p.debug\0' | \
	    xargs $(--verbose?) -0 -r -P$$(J) -n3 objcopy $(OBJCOPY_FLAGS)
	cd $$($(2)_$(3)_LIBDIR) && find -type f -not '(' -iname '*.pc' -or -iname '*.cmake' -or -iname '*.a' -or -iname '*.la' -or -iname '*.def' -or -iname '*.h' ')' \
	    -printf '--add-gnu-debuglink=$$(DST_LIBDIR)/%p.debug\0--strip-debug\0%p\0$$(DST_LIBDIR)/%p\0' | \
	    xargs $(--verbose?) -0 -r -P$$(J) -n4 objcopy $(OBJCOPY_FLAGS) --set-section-flags .text=contents,alloc,load,readonly,code
	touch $$@
else
	cd $$($(2)_$(3)_LIBDIR) && find -type f -not '(' -iname '*.pc' -or -iname '*.cmake' -or -iname '*.a' -or -iname '*.la' -or -iname '*.def' -or -iname '*.h' ')' \
	    -printf '$$(DST_LIBDIR)/%p.debug\0' | xargs $(--verbose?) -0 -r -P$$(J) rm -f
	cd $$($(2)_$(3)_LIBDIR) && find -type f -not '(' -iname '*.pc' -or -iname '*.cmake' -or -iname '*.a' -or -iname '*.la' -or -iname '*.def' -or -iname '*.h' ')' \
	    -printf '--strip-debug\0%p\0$$(DST_LIBDIR)/%p\0' | \
	    xargs $(--verbose?) -0 -r -P$$(J) -n3 objcopy $(OBJCOPY_FLAGS) --set-section-flags .text=contents,alloc,load,readonly,code
	touch $$@
endif

$(1)-$(3)-dist: $$(OBJ)/.$(1)-$(3)-dist
.INTERMEDIATE: $(1)-$(3)-dist

all-$(3)-dist $(1)-dist: $(1)-$(3)-dist
.PHONY: all-$(3)-dist $(1)-dist

all-dist: $(1)-dist
.PHONY: all-dist


$(1)-$(3): $(1)-$(3)-configure $(1)-$(3)-build $(1)-$(3)-dist
.INTERMEDIATE: $(1)-$(3)

all-$(3) $(1): $(1)-$(3)
.PHONY: all-$(3) $(1)

all: $(1)
.PHONY: all

$(2)_$(3)_INCFLAGS = $$(foreach d,$$($(2)_$(3)_DEPS),-I$$($$(d)_$(3)_INCDIR))
$(2)_$(3)_LIBFLAGS = $$(foreach d,$$($(2)_$(3)_DEPS),-L$$($$(d)_$(3)_LIBDIR)/$$($(4)$(3)_LIBDIR)) \
                    $$(foreach d,$$($(2)_$(3)_DEPS),-Wl,-rpath-link=$$($$(d)_$(3)_LIBDIR)/$$($(4)$(3)_LIBDIR)) \

# PKG_CONFIG is intentionally never using CROSS target, as it's missing
# wrapper scripts in the toolchain, we use PKG_CONFIG_LIBDIR directly
# instead.
#
# RC and WIDL are intentionally always using CROSS target, as their
# native version doesn't exist.


$(2)_$(3)_ENV = \
    CARGO_TARGET_$$(call toupper,$$($(3)_CARGO_TARGET))_LINKER="$$($(4)$(3)_TARGET)-gcc" \
    CCACHE_BASEDIR="$$(CCACHE_BASEDIR)" \
    STRIP="$$(STRIP)" \
    AR="$$($(4)$(3)_TARGET)-ar" \
    RANLIB="$$($(4)$(3)_TARGET)-ranlib" \
    CC="$$($(4)$(3)_TARGET)-gcc" \
    CXX="$$($(4)$(3)_TARGET)-g++" \
    LD="$$($(4)$(3)_TARGET)-ld" \
    RC="$$(CROSS$(3)_TARGET)-windres" \
    WIDL="$$(CROSS$(3)_TARGET)-widl" \
    PKG_CONFIG="$$($(3)_TARGET)-pkg-config" \
    PATH="$$(call list-join,:,$$(foreach d,$$($(2)_$(3)_DEPS),$$($$(d)_$(3)_BINDIR)),,:):$$$$PATH" \
    LD_LIBRARY_PATH="$$(call list-join,:,$$(foreach d,$$($(2)_$(3)_DEPS),$$($$(d)_$(3)_LIBDIR)/$$($(4)$(3)_LIBDIR)),,:)$$$$LD_LIBRARY_PATH" \
    PKG_CONFIG_PATH="$$(call list-join,:,$$(foreach d,$$($(2)_$(3)_DEPS),$$($$(d)_$(3)_LIBDIR)/$$($(4)$(3)_LIBDIR)/pkgconfig))" \
    PKG_CONFIG_LIBDIR="/usr/lib/$$($(4)$(3)_LIBDIR)/pkgconfig:/usr/share/pkgconfig" \
    CFLAGS="$$($(2)_$(3)_INCFLAGS) $$($(2)_CFLAGS) $$(COMMON_FLAGS) $$($(3)_COMMON_FLAGS)" \
    CPPFLAGS="$$($(2)_$(3)_INCFLAGS) $$($(2)_CPPFLAGS) $$(COMMON_FLAGS) $$($(3)_COMMON_FLAGS)" \
    CXXFLAGS="$$($(2)_$(3)_INCFLAGS) $$($(2)_CXXFLAGS) $$(COMMON_FLAGS) $$($(3)_COMMON_FLAGS) -std=c++17" \
    LDFLAGS="$$($(2)_$(3)_LIBFLAGS) $$($(2)_$(3)_LDFLAGS) $$($(2)_LDFLAGS) $$($(4)LDFLAGS)" \
    SOURCE_DATE_EPOCH="$$($(2)_$(3)_SOURCE_DATE_EPOCH)" \

ifeq ($(1),wine)

$(2)_$(3)_ENV += \
    CROSSCFLAGS="$$($(2)_$(3)_INCFLAGS) $$($(2)_CFLAGS) $$(COMMON_FLAGS) $$($(3)_COMMON_FLAGS)" \
    CROSSLDFLAGS="$$($(2)_$(3)_LIBFLAGS) $$($(2)_$(3)_LDFLAGS) $$($(2)_LDFLAGS) $$(CROSSLDFLAGS)" \
    i386_AR="$$(CROSSi386_TARGET)-ar" \
    i386_RANLIB="$$(CROSSi386_TARGET)-ranlib" \
    i386_CC="$$(CROSSi386_TARGET)-gcc" \
    i386_CXX="$$(CROSSi386_TARGET)-g++" \
    i386_LD="$$(CROSSi386_TARGET)-ld" \
    i386_CFLAGS="$$($(2)_i386_INCFLAGS) $$($(2)_CFLAGS) $$(COMMON_FLAGS) $$(32_COMMON_FLAGS)" \
    i386_LDFLAGS="$$($(2)_i386_LIBFLAGS) $$($(2)_i386_LDFLAGS) $$($(2)_LDFLAGS) $$(CROSSLDFLAGS)" \
    i386_PKG_CONFIG_LIBDIR="/usr/lib/$$(CROSSi386_LIBDIR)/pkgconfig:/usr/share/pkgconfig" \
    x86_64_AR="$$(CROSSx86_64_TARGET)-ar" \
    x86_64_RANLIB="$$(CROSSx86_64_TARGET)-ranlib" \
    x86_64_CC="$$(CROSSx86_64_TARGET)-gcc" \
    x86_64_CXX="$$(CROSSx86_64_TARGET)-g++" \
    x86_64_LD="$$(CROSSx86_64_TARGET)-ld" \
    x86_64_CFLAGS="$$($(2)_x86_64_INCFLAGS) $$($(2)_CFLAGS) $$(COMMON_FLAGS) $$(64_COMMON_FLAGS)" \
    x86_64_LDFLAGS="$$($(2)_x86_64_LIBFLAGS) $$($(2)_x86_64_LDFLAGS) $$($(2)_LDFLAGS) $$(CROSSLDFLAGS)" \
    x86_64_PKG_CONFIG_LIBDIR="/usr/lib/$$(CROSSx86_64_LIBDIR)/pkgconfig:/usr/share/pkgconfig" \

endif

endef

ifneq ($(UNSTRIPPED_BUILD),)
install-strip = objcopy $(OBJCOPY_FLAGS) --only-keep-debug $(1) $(2)/$(notdir $(1)).debug && \
                objcopy $(OBJCOPY_FLAGS) --add-gnu-debuglink=$(2)/$(notdir $(1)).debug --strip-debug $(1) $(2)/$(notdir $(1))
else
install-strip = objcopy $(OBJCOPY_FLAGS) --strip-debug $(1) $(2)/$(notdir $(1)) && rm -f $(2)/$(notdir $(1)).debug
endif

i386_TARGET := i686-linux-gnu
x86_64_TARGET := x86_64-linux-gnu
CROSSi386_TARGET := i686-w64-mingw32
CROSSx86_64_TARGET := x86_64-w64-mingw32

i386_LIBDIR := i386-linux-gnu
x86_64_LIBDIR := x86_64-linux-gnu
CROSSi386_LIBDIR := i386-w64-mingw32
CROSSx86_64_LIBDIR := x86_64-w64-mingw32

i386_WINEDIR := wine/i386-unix
x86_64_WINEDIR := wine/x86_64-unix
CROSSi386_WINEDIR := wine/i386-windows
CROSSx86_64_WINEDIR := wine/x86_64-windows

$(OBJ)/.%-i386-post-build:
	touch $@
$(OBJ)/.%-x86_64-post-build:
	touch $@

rules-common = $(call create-rules-common,$(1),$(call toupper,$(1)),$(2),$(3))
