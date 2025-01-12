# parameters:
#   $(1): lowercase package name
#   $(2): uppercase package name
#   $(3): 32/64, build type
#
define create-rules-cargo
$(call create-rules-common,$(1),$(2),$(3))

$$(OBJ)/.$(1)-$(3)-configure:
	@echo ":: configuring $(1)-$(3)..." >&2
	touch $$@

$$(OBJ)/.$(1)-$(3)-build:
	@echo ":: building $(1)-$(3)..." >&2
	cd $$($(2)_SRC) && env $$($(2)_$(3)_ENV) \
	cargo build $(--quiet?) --release \
	      $$(filter -j%,$$(MAKEFLAGS)) \
	      --target-dir $$($(2)_$(3)_OBJ) \
	      $$($(3)_CARGO_ARGS) \
	      $$($(2)_CARGO_ARGS) \
	      $$($(2)_$(3)_CARGO_ARGS)
	touch $$@
endef

rules-cargo = $(call create-rules-cargo,$(1),$(call toupper,$(1)),$(2))

32_CARGO_TARGET := i686-unknown-linux-gnu
64_CARGO_TARGET := x86_64-unknown-linux-gnu

32_CARGO_ARGS := --target $(32_CARGO_TARGET)
64_CARGO_ARGS := --target $(64_CARGO_TARGET)
