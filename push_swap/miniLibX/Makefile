#
#
GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CHANGE = $(BLUE)
TAB = "\	\	"
FTAB = "\	\	\	"

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "\n$(NOM):$(TAB)$(YELLOW)object files$(TAB)$(GREEN)were created.$(RESET)"
	@ar rcs $(NOM) $(OBJ)
	@echo "$(NOM):$(TAB)$(YELLOW)$(NOM)$(TAB)$(GREEN)was  created.$(RESET)\n"
	@ranlib $(NOM)

clean:
	@rm -f $(OBJ) *~
	@echo "\n$(NOM):$(TAB)$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)"
	@rm -f $(NOM)
	@echo "$(NOM):$(TAB)$(YELLOW)$(NOM)$(TAB)$(RED)was  deleted.$(RESET)"
	@rm -f mlx_app
	@echo "$(NOM):$(TAB)$(YELLOW)mlx_app$(FTAB)$(RED)wes  deleted.$(RESET)"


re: clean all
