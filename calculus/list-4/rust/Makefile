
CARGO := $(shell command -v cargo 2>/dev/null || printf '%s' "$(HOME)/.cargo/bin/cargo")

.PHONY: install build run clean

install:
	@if [ ! -x "$(CARGO)" ]; then \
		curl --proto '=https' --tlsv1.2 -sSf \
			https://sh.rustup.rs | sh -s -- -y --profile minimal; \
	fi
	@$(CARGO) build --release

build:
	@$(CARGO) build --release

run:
	@$(CARGO) run --release

clean:
	@$(CARGO) clean
	@rm -rf results

