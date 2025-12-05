CXX      = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

MANDATORY = tester_ex00 tester_ex01
BONUS     = tester_ex02

RUN_ALL_SRC := run_all.cpp
RUN_ALL_BIN := testercpp

GREEN  = \033[0;32m
RED    = \033[0;31m
YELLOW = \033[1;33m
BLUE   = \033[0;34m
RESET  = \033[0m


all: $(MANDATORY)
	@echo "$(GREEN)✅ Mandatory testers built successfully!$(RESET)"

$(MANDATORY):
	@echo "$(BLUE)➡️  Building in $@ ...$(RESET)"
	@$(MAKE) -C $@

bonus:
	@if [ -d $(BONUS) ]; then \
        echo "$(BLUE)➡️  Building bonus in $(BONUS)...$(RESET)"; \
        $(MAKE) -C $(BONUS); \
        echo "$(GREEN)✅ Bonus tester built successfully!$(RESET)"; \
    else \
        echo "$(YELLOW)⚠️ Skipping bonus tester (not found)$(RESET)"; \
    fi

$(RUN_ALL_BIN): $(RUN_ALL_SRC)
	@echo "$(BLUE)➡️  Compiling unified runner...$(RESET)"
	$(CXX) $(CXXFLAGS) $< -o $@

run_all: banner all $(RUN_ALL_BIN)
	@echo "$(BLUE)🚀 Launching all testers via run_all...$(RESET)"
	./$(RUN_ALL_BIN)


clean:
	@echo "$(YELLOW)🧹 Cleaning testers...$(RESET)"
	@for dir in $(MANDATORY) $(BONUS); do \
        if [ -d $$dir ]; then \
            $(MAKE) -C $$dir clean; \
        else \
            echo "$(YELLOW)⚠️ Skipping $$dir (not found)$(RESET)"; \
        fi \
	done
	@rm -f $(RUN_ALL_BIN)
	@echo "$(GREEN)✨ Clean complete$(RESET)"

banner:
	@echo "$(BLUE)====================================================$(RESET)"
	@echo "████████╗███████╗███████╗████████╗███████╗██████╗ "
	@echo "╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗"
	@echo "   ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝"
	@echo "   ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗"
	@echo "   ██║   ███████╗███████║   ██║   ███████╗██║  ██║"
	@echo "   ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝"
	@echo "$(GREEN)📂 TESTER SUITE$(RESET)"
	@echo "$(YELLOW)👨‍💻 By mhamdali$(RESET)"
	@echo "$(BLUE)====================================================$(RESET)"

help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo "  $(GREEN)make all$(RESET)      - Build mandatory testers"
	@echo "  $(GREEN)make bonus$(RESET)    - Build bonus tester if present"
	@echo "  $(GREEN)make run_all$(RESET)  - Build unified runner and execute all testers (with banner)"
	@echo "  $(GREEN)make clean$(RESET)    - Clean all testers and runner"
	@echo "  $(GREEN)make banner$(RESET)   - Show big banner"

.PHONY: all clean banner help $(MANDATORY) bonus run_all
