/*
** EPITECH PROJECT, 2019
** h
** File description:
** maxime eleonore
*/


struct s_minishell {
    char **env;
    char **cmd;
};

typedef struct s_minishell minishell_t;

int my_words(char *str);
int my_len(char *str);
char **my_str_to_word_tab(char *str);
int my_cd(char **cmd, char **env);
int find_in_env(char **env, char const *search);
int my_builtin(char **cmd, minishell_t *minishell);
