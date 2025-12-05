CXX      = c++
CXXFLAGS = -std=c++17 

MANDATORY = tester_ex00 tester_ex01
BONUS     = tester_ex02

RUN_ALL_SRC := run_all.cpp
RUN_ALL_BIN := testercpp


HEADER  = \033[1;38;5;39m
SUCCESS = \033[1;38;5;46m
ERROR   = \033[1;38;5;196m
WARNING = \033[1;38;5;214m
INFO    = \033[1;38;5;117m
ACCENT  = \033[1;38;5;141m
DIM     = \033[2;38;5;245m
RESET   = \033[0m
BOLD    = \033[1m

.PHONY: all bonus clean fclean re run_all banner help $(MANDATORY)

all: banner $(MANDATORY)
	@echo ""
	@echo "$(SUCCESS)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(SUCCESS)$(BOLD)  ✓ Mandatory testers built successfully$(RESET)"
	@echo "$(SUCCESS)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo ""

$(MANDATORY):
	@echo "$(INFO)╭────────────────────────────────────────────╮$(RESET)"
	@echo "$(INFO)│$(RESET) $(BOLD)Building:$(RESET) $(ACCENT)$@$(RESET)"
	@echo "$(INFO)╰────────────────────────────────────────────╯$(RESET)"
	@printf "  $(DIM)⏳ Compiling$(RESET)"
	@$(MAKE) -C $@ --no-print-directory > /dev/null 2>&1 & \
	pid=$$!; \
	while kill -0 $$pid 2>/dev/null; do \
		printf "."; \
		sleep 0.3; \
	done; \
	wait $$pid; \
	status=$$?; \
	printf "\r\033[K"; \
	if [ $$status -eq 0 ]; then \
		echo "  $(SUCCESS)✓$(RESET) $@ $(DIM)completed$(RESET)"; \
	else \
		echo "  $(ERROR)✗$(RESET) $@ $(ERROR)failed$(RESET)"; \
		echo "$(ERROR)Showing compilation errors:$(RESET)"; \
		$(MAKE) -C $@; \
		exit 1; \
	fi
	@echo ""

bonus: banner
	@if [ -d $(BONUS) ]; then \
		echo "$(INFO)╭────────────────────────────────────────────╮$(RESET)"; \
		echo "$(INFO)│$(RESET) $(ACCENT)Building Bonus:$(RESET) $(BOLD)$(BONUS)$(RESET)"; \
		echo "$(INFO)╰────────────────────────────────────────────╯$(RESET)"; \
		printf "  $(DIM)⏳ Compiling$(RESET)"; \
		$(MAKE) -C $(BONUS) --no-print-directory > /dev/null 2>&1 & \
		pid=$$!; \
		while kill -0 $$pid 2>/dev/null; do \
			printf "."; \
			sleep 0.3; \
		done; \
		wait $$pid; \
		status=$$?; \
		printf "\r\033[K"; \
		if [ $$status -eq 0 ]; then \
			echo "  $(SUCCESS)✓$(RESET) $(BONUS) $(DIM)completed$(RESET)"; \
			echo ""; \
			echo "$(SUCCESS)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
			echo "$(SUCCESS)$(BOLD)  ⭐ Bonus tester built successfully$(RESET)"; \
			echo "$(SUCCESS)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
			echo ""; \
		else \
			echo "  $(ERROR)✗$(RESET) $(BONUS) $(ERROR)failed$(RESET)"; \
			echo "$(ERROR)Showing compilation errors:$(RESET)"; \
			$(MAKE) -C $(BONUS); \
			exit 1; \
		fi; \
	else \
		echo "$(WARNING)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(WARNING)  ⚠  Bonus directory not found - Skipping$(RESET)"; \
		echo "$(WARNING)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo ""; \
	fi

$(RUN_ALL_BIN): $(RUN_ALL_SRC)
	@printf "  $(DIM)⚙  Compiling unified runner$(RESET)"
	@$(CXX) $(CXXFLAGS) $< -o $@ > /dev/null 2>&1 & \
	pid=$$!; \
	while kill -0 $$pid 2>/dev/null; do \
		printf "."; \
		sleep 0.2; \
	done; \
	wait $$pid; \
	status=$$?; \
	printf "\r\033[K"; \
	if [ $$status -eq 0 ]; then \
		echo "  $(SUCCESS)✓$(RESET) Runner $(DIM)compiled$(RESET)"; \
	else \
		echo "  $(ERROR)✗$(RESET) Runner $(ERROR)compilation failed$(RESET)"; \
		echo "$(ERROR)Showing compilation errors:$(RESET)"; \
		$(CXX) $(CXXFLAGS) $< -o $@; \
		exit 1; \
	fi
	@echo ""

run_all: all $(RUN_ALL_BIN)
	@if [ -d $(BONUS) ]; then \
		echo "$(ACCENT)$(BOLD)Including bonus tester...$(RESET)"; \
		printf "  $(DIM)⏳ Building$(RESET)"; \
		$(MAKE) -C $(BONUS) --no-print-directory > /dev/null 2>&1 & \
		pid=$$!; \
		while kill -0 $$pid 2>/dev/null; do \
			printf "."; \
			sleep 0.3; \
		done; \
		wait $$pid; \
		status=$$?; \
		printf "\r\033[K"; \
		if [ $$status -eq 0 ]; then \
			echo "  $(SUCCESS)✓$(RESET) Bonus $(DIM)included$(RESET)"; \
		else \
			echo "  $(WARNING)⚠$(RESET) Bonus $(WARNING)failed, continuing without it$(RESET)"; \
		fi; \
		echo ""; \
	fi
	@echo "$(HEADER)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(HEADER)$(BOLD)       🚀 Launching All Testers$(RESET)"
	@echo "$(HEADER)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo ""
	@./$(RUN_ALL_BIN)

clean:
	@echo "$(WARNING)╭────────────────────────────────────────────╮$(RESET)"
	@echo "$(WARNING)│$(RESET) $(BOLD)🧹 Cleaning testers$(RESET)"
	@echo "$(WARNING)╰────────────────────────────────────────────╯$(RESET)"
	@for dir in $(MANDATORY) $(BONUS); do \
		if [ -d $$dir ]; then \
			printf "  $(DIM)→$(RESET) Cleaning $$dir"; \
			$(MAKE) -C $$dir clean --no-print-directory > /dev/null 2>&1; \
			printf "\r\033[K"; \
			echo "  $(SUCCESS)✓$(RESET) Cleaned $$dir"; \
		fi \
	done
	@rm -f $(RUN_ALL_BIN)
	@echo ""
	@echo "$(SUCCESS)  ✨ Clean complete$(RESET)"
	@echo ""

fclean: clean
	@echo "$(ERROR)╭────────────────────────────────────────────╮$(RESET)"
	@echo "$(ERROR)│$(RESET) $(BOLD)🗑  Full clean in progress$(RESET)"
	@echo "$(ERROR)╰────────────────────────────────────────────╯$(RESET)"
	@for dir in $(MANDATORY) $(BONUS); do \
		if [ -d $$dir ]; then \
			printf "  $(DIM)→$(RESET) Deep cleaning $$dir"; \
			$(MAKE) -C $$dir fclean --no-print-directory > /dev/null 2>&1; \
			printf "\r\033[K"; \
			echo "  $(SUCCESS)✓$(RESET) Deep cleaned $$dir"; \
		fi \
	done
	@echo ""
	@echo "$(SUCCESS)  ✨ Full clean complete$(RESET)"
	@echo ""

re: fclean all

banner:
	@echo ""
	@echo "$(HEADER)$(BOLD)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(INFO)  ████████╗ ███████╗ ███████╗ ████████╗ ███████╗ ██████╗$(RESET)"
	@echo "$(INFO)  ╚══██╔══╝ ██╔════╝ ██╔════╝ ╚══██╔══╝ ██╔════╝ ██╔══██╗$(RESET)"
	@echo "$(INFO)     ██║    █████╗   ███████╗    ██║    █████╗   ██████╔╝$(RESET)"
	@echo "$(INFO)     ██║    ██╔══╝   ╚════██║    ██║    ██╔══╝   ██╔══██╗$(RESET)"
	@echo "$(INFO)     ██║    ███████╗ ███████║    ██║    ███████╗ ██║  ██║$(RESET)"
	@echo "$(INFO)     ╚═╝    ╚══════╝ ╚══════╝    ╚═╝    ╚══════╝ ╚═╝  ╚═╝$(RESET)"
	@echo ""
	@echo "$(SUCCESS)$(BOLD)              📂 CPP MODULE TESTER SUITE$(RESET)"
	@echo "$(ACCENT)$(BOLD)                 👨‍💻 Crafted by mhamdali$(RESET)"
	@echo "$(HEADER)$(BOLD)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo ""

help:
	@echo ""
	@echo "$(HEADER)$(BOLD)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(HEADER)$(BOLD)           📖 Available Commands$(RESET)"
	@echo "$(HEADER)$(BOLD)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo ""
	@echo "  $(SUCCESS)$(BOLD)make all$(RESET)      $(DIM)→$(RESET) Build mandatory testers (ex00, ex01)"
	@echo "  $(SUCCESS)$(BOLD)make bonus$(RESET)    $(DIM)→$(RESET) Build bonus tester (ex02) if available"
	@echo "  $(SUCCESS)$(BOLD)make run_all$(RESET)  $(DIM)→$(RESET) Build & execute all testers (includes bonus)"
	@echo "  $(WARNING)$(BOLD)make clean$(RESET)    $(DIM)→$(RESET) Remove object files"
	@echo "  $(ERROR)$(BOLD)make fclean$(RESET)   $(DIM)→$(RESET) Remove object files and executables"
	@echo "  $(INFO)$(BOLD)make re$(RESET)       $(DIM)→$(RESET) Rebuild everything from scratch"
	@echo "  $(ACCENT)$(BOLD)make banner$(RESET)   $(DIM)→$(RESET) Display the awesome banner"
	@echo "  $(HEADER)$(BOLD)make help$(RESET)     $(DIM)→$(RESET) Show this help message"
	@echo ""
	@echo "$(WARNING)$(BOLD)Note:$(RESET) Bonus tester (ex02) is automatically included"
	@echo "      if the directory exists. Otherwise, it's gracefully skipped."
	@echo ""