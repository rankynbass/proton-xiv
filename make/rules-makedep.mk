# parameters:
#   $(1): lowercase package name
#   $(2): uppercase package name
#   $(3): 32/64, build type
#
define create-rules-makedep
$(call create-rules-common,$(1),$(2),$(3)) # cannot pass $(4)/CROSS here because of link flags for remaining .dll.so modules

$$(OBJ)/.$(1)-$(3)-configure:
	@echo ":: configuring $(1)-$(3)..." >&2

	sed -e '/^all:$$$$/,$$$$c all:' \
	    -e '/^SUBDIRS/,/[^\\]$$$$/c SUBDIRS = $$($(2)_SRC)' \
	    \
	    -e '/^srcdir/a objdir = $$(WINE_$(3)_OBJ)' \
	    -e '/^prefix/c prefix = $$($(2)_$(3)_DST)' \
	    -e '/^libdir/c libdir = $$($(2)_$(3)_LIBDIR)' \
	    -e '/^toolsdir/c toolsdir = $$(WINE_$(3)_OBJ)' \
	    \
	    -e '/^CFLAGS/c CFLAGS = $$($(2)_$(3)_INCFLAGS) $$($(2)_CFLAGS) $$(COMMON_FLAGS) $$($(3)_COMMON_FLAGS)' \
	    -e '/^CPPFLAGS/c CPPFLAGS = $$($(2)_$(3)_INCFLAGS) $$($(2)_CPPFLAGS) $$(COMMON_FLAGS) $$($(3)_COMMON_FLAGS)' \
	    -e '/^CXXFLAGS/c CXXFLAGS = $$($(2)_$(3)_INCFLAGS) $$($(2)_CXXFLAGS) $$(COMMON_FLAGS) $$($(3)_COMMON_FLAGS) -std=c++17' \
	    -e '/^LDFLAGS/c LDFLAGS = $$($(2)_$(3)_LIBFLAGS) $$($(2)_$(3)_LDFLAGS) $$($(2)_LDFLAGS)' \
	    \
	    -e '/^x86_64_CC/a x86_64_CXX = $$(CROSS64_TARGET)-g++' \
	    -e '/^x86_64_CFLAGS/c x86_64_CFLAGS = $$($(2)_64_INCFLAGS) $$($(2)_CFLAGS) $$(COMMON_FLAGS) $$(64_COMMON_FLAGS)' \
	    -e '/^x86_64_CPPFLAGS/c x86_64_CPPFLAGS = $$($(2)_64_INCFLAGS) $$($(2)_CPPFLAGS) $$(COMMON_FLAGS) $$(64_COMMON_FLAGS)' \
	    -e '/^x86_64_CXXFLAGS/c x86_64_CXXFLAGS = $$($(2)_64_INCFLAGS) $$($(2)_CXXFLAGS) $$(COMMON_FLAGS) $$(64_COMMON_FLAGS) -std=c++17' \
	    -e '/^x86_64_LDFLAGS/c x86_64_LDFLAGS = $$($(2)_64_LIBFLAGS) $$($(2)_64_LDFLAGS) $$(CROSSLDFLAGS)' \
	    \
	    -e '/^i386_CC/a i386_CXX = $$(CROSS32_TARGET)-g++' \
	    -e '/^i386_CFLAGS/c i386_CFLAGS = $$($(2)_32_INCFLAGS) $$($(2)_CFLAGS) $$(COMMON_FLAGS) $$(32_COMMON_FLAGS)' \
	    -e '/^i386_CPPFLAGS/c i386_CPPFLAGS = $$($(2)_32_INCFLAGS) $$($(2)_CPPFLAGS) $$(COMMON_FLAGS) $$(32_COMMON_FLAGS)' \
	    -e '/^i386_CXXFLAGS/c i386_CXXFLAGS = $$($(2)_32_INCFLAGS) $$($(2)_CXXFLAGS) $$(COMMON_FLAGS) $$(32_COMMON_FLAGS) -std=c++17' \
	    -e '/^i386_LDFLAGS/c i386_LDFLAGS = $$($(2)_32_LIBFLAGS) $$($(2)_32_LDFLAGS) $$(CROSSLDFLAGS)' \
	    \
	    -e 's@UNIXLDFLAGS =@UNIXLDFLAGS = -L$$(WINE_$(3)_LIBDIR)/$$($(3)_WINEDIR) -l:ntdll.so@' \
	    $$(WINE_$(3)_OBJ)/Makefile > $$($(2)_$(3)_OBJ)/Makefile

	cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$(WINE_$(3)_OBJ)/tools/makedep

	touch $$@

$$(OBJ)/.$(1)-$(3)-build:
	@echo ":: building $(1)-$(3)..." >&2
	+cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$(BEAR) $$(MAKE)
	cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$(MAKE) install
	touch $$@
endef

rules-makedep = $(call create-rules-makedep,$(1),$(call toupper,$(1)),$(2),$(3))
