/*
** EPITECH PROJECT, 2019
** sort
** File description:
** Maxime ELEONORE
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <my.h>
#include "my_ls.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

char *get_right(char const *path)
{
    struct stat info;
    char *right = malloc(sizeof(char) * 12);

    stat(path, &info);
    right[0] = (S_ISDIR(info.st_mode)) ? 'd' : '-';
    right[1] = (info.st_mode & S_IRUSR) ? 'r' : '-';
    right[2] = (info.st_mode & S_IWUSR) ? 'w' : '-';
    right[3] = (info.st_mode & S_IXUSR) ? 'x' : '-';
    right[4] = (info.st_mode & S_IRGRP) ? 'r' : '-';
    right[5] = (info.st_mode & S_IWGRP) ? 'w' : '-';
    right[6] = (info.st_mode & S_IXGRP) ? 'x' : '-';
    right[7] = (info.st_mode & S_IROTH) ? 'r' : '-';
    right[8] = (info.st_mode & S_IWOTH) ? 'w' : '-';
    right[9] = (info.st_mode & S_IXOTH) ? 'x' : '-';
    right[9] = (info.st_mode & S_ISVTX && right[9] == 'x') ? 't' : right[9];
    right[9] = (info.st_mode & S_ISVTX && right[9] == '-') ? 'T' : right[9];
    right[10] = '.';
    right[11] = '\0';
    return (right);
}

char *get_hardlink(char const *path)
{
    struct stat info;
    char *hardlink;

    stat(path, &info);
    hardlink = my_itoa((int)info.st_nlink);
    hardlink = my_strcat(get_right(path), hardlink);
    return (hardlink);
}

char *get_name(char const *path)
{
    struct stat stats;
    struct passwd *info;
    struct group *grp;
    char *names;

    stat(path, &stats);
    info = getpwuid(stats.st_uid);
    grp = getgrgid(stats.st_gid);
    names = my_strcat(info->pw_name, grp->gr_name);
    names = my_strcat(get_hardlink(path), names);
    return (names);
}

char *get_size(char const *path)
{
    struct stat info;
    char *size;

    stat(path, &info);
    size = my_itoa((int)info.st_size);
    size = my_strcat(get_name(path), size);
    return (size);
}

char *get_modif(char const *path)
{
    struct stat info;
    char *modif;

    stat(path, &info);
    modif = ctime(&info.st_mtim.tv_sec);
    modif  = modifmodif(modif);
    modif = my_strcat(get_size(path), modif);
    return (modif);
}