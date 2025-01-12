# parameters:
#   $(1): lowercase package name
#   $(2): uppercase package name
#   $(3): 32/64, build type
#   $(4): CROSS/<empty>, cross compile
#
define create-rules-autoconf
$(call create-rules-common,$(1),$(2),$(3),$(4))

$$($(2)_SRC)/configure: $$($(2)_ORIGIN)/configure.ac | $$(OBJ)/.$(1)-post-source
	@echo ":: autoreconfing $(1)..." >&2
	cd "$$($(2)_SRC)" && autoreconf -fiv

$$(OBJ)/.$(1)-$(3)-configure: $$($(2)_SRC)/configure
	@echo ":: configuring $(1)-$(3)..." >&2
	rm -rf "$$($(2)_$(3)_OBJ)/config.cache"

	cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$($(2)_SRC)/configure $(--quiet?) -C \
	    --prefix="$$($(2)_$(3)_DST)" \
	    --libdir="$$($(2)_$(3)_DST)/lib" \
	    --host="$$($(4)$(3)_TARGET)" \
	    $$($(2)_$(3)_ENV) \
	    $$($(3)_AUTOCONF_ARGS) \
	    $$($(2)_AUTOCONF_ARGS) \
	    $$($(2)_$(3)_AUTOCONF_ARGS)

	touch $$@

$$(OBJ)/.$(1)-$(3)-build:
	@echo ":: building $(1)-$(3)..." >&2
	+cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$(BEAR) $$(MAKE)
	cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$(MAKE) install
	touch $$@
endef

rules-autoconf = $(call create-rules-autoconf,$(1),$(call toupper,$(1)),$(2),$(3))
