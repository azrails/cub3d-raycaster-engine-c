#include "cub3d.h"

/*
static int ft_ones(t_all *settings, int pos)
{
    int j;

    j = 0;
    while(settings->map.lines[pos][j])
        {
            if(settings->map.lines[pos][j] == '0' || settings->map.lines[pos][j] == 'S' 
                || settings->map.lines[pos][j] == 'N' || settings->map.lines[pos][j] == 'W' 
                    || settings->map.lines[pos][j] == 'E')
                return(0);
            j++;
        }
    return(1);
}
static int ft_first_last(t_all *settings, int fl)
{
    int pos;

    pos = settings->position.x;
    while (settings->map.lines[pos] && pos >= 0)
    {
        if (ft_ones(settings, pos))
            break;
        if (fl == 1)
            pos++;
        else
            pos--;
    }
    if (pos == settings->position.x || pos == -1)
    {
        settings->err = -5;
        errors(ft_clear(settings));
    }
    return(pos);
}

static int flone(char *line, int i, int x)
{
    int pos1;

    pos1 = 0;
    while(line[i])
    {
        if(line[i] == '1')
        {
            if (x == 1)
                return(i);
            else
                pos1 = i;
        }
        i++;
    }
    return(pos1);
}

static void check_check(t_all *settings)
{

}
static void ft_true_map_bottom(t_all *settings, int last_str, int i)
{
    while (i < last_str)
    {
        settings->check.fo1 = flone(settings->map.lines[i], 0, 1);
        settings->check.lo1 = flone(settings->map.lines[i], 0, 2);
        settings->check.fo2 = flone(settings->map.lines[i + 1], 0, 1);
        settings->check.lo2 = flone(settings->map.lines[i + 1], 0, 2);
        if(settings->check.c >= 0 && settings->check.fo2 != settings->check.c)
            check_check(settings);
        printf("fo1 : %d\n",settings->check.fo1);
        printf("fo2 : %d\n",settings->check.fo2);
        if(settings->check.fo1 != settings->check.fo2)
        {
            while ((settings->check.fo1 < settings->check.lo1) && (settings->check.fo2 < settings->check.lo2))
            {
                if (settings->check.fo1  < settings->check.fo2)
                    settings->check.fo1 = flone(settings->map.lines[i],settings->check.fo1 + 1, 1);
                if (settings->check.fo1  > settings->check.fo2)
                    settings->check.fo2 = flone(settings->map.lines[i + 1],settings->check.fo2 + 1, 1);
                if (settings->check.fo1  == settings->check.fo2)
                {
                    settings->check.c = settings->check.fo2;
                    break;
                }
            }
            if ((settings->check.fo1 >= settings->check.lo1 || settings->check.fo2 >= settings->check.lo2))
            {
                settings->err = -5;
                errors(ft_clear(settings));
            }
        }
        else
            settings->check.c = -1
        i++;
    }
}*/
/*
static int ch(t_all *settings,int last_str, int first_str ,int fl)
{
    int b;
    int x;

    x = 0;
    b = ft_strlen(settings->map.lines[first_str + 1]);
    printf("string : %d, pos : %d\n",first_str,fl);
    if (fl < 0 || (settings->map.lines[first_str][fl] != '1'|| !(settings->map.lines[first_str][fl])))
        return (2);
    if((b > fl && settings->map.lines[first_str + 1][fl] == '1' && first_str < last_str) && x == 0)
        x = ch(settings,last_str,first_str + 1,fl);
    if((b > fl && settings->map.lines[first_str + 1][fl] != '1' && first_str < last_str && fl >= 0) && x == 0)
        x = ch(settings,last_str,first_str,fl + 1);
    if((b > fl && settings->map.lines[first_str + 1][fl] != '1' && first_str < last_str && fl >= 0) && x == 0)
        x = ch(settings,last_str,first_str,fl - 1);
    if (first_str == last_str)
    {
        settings->check.c++;
        printf("YES\n\n\n");
        return(1);
    }
    if(x == 1)
        return(1);
    if(x == 2)
        return(2);
    return (0);
}


void    ft_check_lines(t_all *settings)
{
    int last_str;
    int first_str;
    //int i;
    int fl;
    int x = 0;


	settings->check.fo1 = 0;
	settings->check.lo1 = 0;
	settings->check.fo2 = 0;
	settings->check.lo2 = 0;
    settings->check.c = 0;
    //i = settings->position.x;
    last_str = ft_first_last(settings, 1);
    first_str = ft_first_last(settings, 2);
    fl = flone(settings->map.lines[first_str],0,1);
    printf("l: %d\n",last_str);
    printf("f: %d\n",first_str);
    //ft_true_map_bottom(settings, last_str, i);
    x = ft_strlen(settings->map.lines[first_str]);
    while (fl < x)
    {
        ch(settings,last_str,first_str,fl);
        fl++;
    }
        printf("%d",settings->check.c);
}*/

static int ft_len_map(t_all *settings)
{
    int count;

    count = 0;
    while(settings->map.lines[count])
        count++;
    return(count);
}

static int tr(t_all *settings, int i, int j)
{
     if(settings->map.lines[i][j] == '0' || settings->map.lines[i][j] == '2' 
        || settings->map.lines[i][j] == 'N'|| settings->map.lines[i][j] == 'S' 
        || settings->map.lines[i][j] == 'W' || settings->map.lines[i][j] == 'E'
        || settings->map.lines[i][j] == '1')
        return (1);
    return (0);
}

static int checker(t_all *settings, int i, int j)
{
    int y;

    if(settings->map.lines[i][j] == '0' || settings->map.lines[i][j] == '2' 
        || settings->map.lines[i][j] == 'N'|| settings->map.lines[i][j] == 'S' 
        || settings->map.lines[i][j] == 'W' || settings->map.lines[i][j] == 'E')
    {
         if (!(tr(settings,i,j - 1)) || !(tr(settings,i,j + 1)))
              return (0);
        y = ft_strlen(settings->map.lines[i + 1]);
        if( j < y && (!(tr(settings,i + 1,j - 1)) || !(tr(settings,i + 1,j + 1)) 
            || !(tr(settings,i + 1, j))))
              return (0);
        y = ft_strlen(settings->map.lines[i - 1]);
        if( j < y && (!(tr(settings,i - 1,j - 1)) || !(tr(settings,i - 1,j + 1)) 
            || !(tr(settings,i - 1, j))))
              return (0);
    }
    return (1);
}

int    ft_check_lines(t_all *settings)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    x = ft_len_map(settings);
    while(settings->map.lines[i])
    {
        j = 0;
        y = ft_strlen(settings->map.lines[i]);
        while(settings->map.lines[i][j])
        {
            if ((i == 0 || i == (x - 1) || j == 0 || j == (y - 1)) 
                && (settings->map.lines[i][j] != '1' && settings->map.lines[i][j] != ' '))
              return (-3);
            if (!(checker(settings, i, j)))
              return (-3);
            j++;
        }
        i++;
    }
    return (1);
}