NAME 		:= liblexer.a
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -pedantic -g

HEADERS		=	. \
				../ \
				../libft/ \
				../signal/includes/ \


INCLUDES	=	$(addprefix -I, $(HEADERS))

SRCS = new_lexer.c\
		delete_lexer.c\
		new_token.c\
		next_token.c\
		read_char.c\
		delete_token.c\
		print_token.c\
		new_ident_token.c\
		peek_char.c\
		get_literal.c\
		is_redirect.c\
		skip_whitespace.c\
		join_new_line.c\
		new_quote_token.c\
		is_word_token.c\
		add_heredoc_delimiter.c\
		read_heredoc.c\
		print_kvs.c\
		is_metachar.c\
		expand_envvar.c\
		word_split.c\
		expand_quote.c\
		is_valid_tokens.c\
		token_dup.c\
		analyze_lex.c\
		delete_lexer_product.c\
		create_tmpfile.c\
		register_heredocs.c\
		join_line_to_buffer.c\
		word_split_2.c\
		expand_envvar_2.c\

OBJS = ${SRCS:.c=.o}

DEPS = $(OBJS:.o=.d)

RED			=	'\033[31m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[33m'
RESET		=	'\033[0m'


all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) ${OBJS}
	@echo $(YELLOW)"@@@@@ $(NAME) compiling done @@@@@"$(RESET)

%.o: %.c
	@echo $(GREEN)"Creating: $@"$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY: clean
clean:
	@rm -f $(OBJS)
	@echo $(RED)"REMOVE OBJECT FILES $(OBJS)"$(RESET)

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@echo $(RED)"REMOVE $(NAME)"$(RESET)

re: fclean all
