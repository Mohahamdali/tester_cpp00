SRCFL = PhoneBook.cpp Contact.cpp

OBJFL = $(SRCFL:.cpp=.o)

NAME = phonebook
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++
RM = rm -rf

all : $(NAME)

$(NAME): $(OBJFL)
	$(CPP) $(FLAGS) $^ -o $@

%.o : %.cpp PhoneBook.hpp Contact.hpp
	$(CPP) -c $(FLAGS) $< -o $@

clean:
	$(RM) $(OBJFL)
fclean : clean
	$(RM) $(NAME)
re: fclean all