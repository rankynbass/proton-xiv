# parameters:
#   $(1): lowercase package name
#   $(2): uppercase package name
#   $(3): build target arch
#   $(4): build target os
#
define create-rules-configure
$(call create-rules-common,$(1),$(2),$(3),$(4))
ifneq ($(findstring $(3)-$(4),$(ARCHS)),)

$$(OBJ)/.$(1)-$(3)-configure:
	@echo ":: configuring $(1)-$(3)..." >&2

	cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$($(2)_SRC)/configure $(--quiet?) \
	    --cross-prefix=$$($(3)-$(4)_TARGET)- \
	    --prefix="$$($(2)_$(3)_DST)" \
	    --libdir="$$($(2)_$(3)_LIBDIR)/$$($(3)-$(4)_LIBDIR)" \
	    $$($(3)-$(4)_CONFIGURE_ARGS) \
	    $$($(2)_CONFIGURE_ARGS) \
	    $$($(2)_$(3)_CONFIGURE_ARGS)

	touch $$@

$$(OBJ)/.$(1)-$(3)-build:
	@echo ":: building $(1)-$(3)..." >&2
	+cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$(BEAR) $$(MAKE)
	cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$(MAKE) install
	touch $$@
endif
endef

i386-unix_CONFIGURE_ARGS := --arch=x86 --target-os=linux
x86_64-unix_CONFIGURE_ARGS := --arch=x86_64 --target-os=linux
i386-windows_CONFIGURE_ARGS := --arch=x86 --target-os=windows
x86_64-windows_CONFIGURE_ARGS := --arch=x86_64 --target-os=windows

rules-configure = $(call create-rules-configure,$(1),$(call toupper,$(1)),$(2),$(3))
