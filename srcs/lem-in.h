/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 12:10:40 by cheron            #+#    #+#             */
/*   Updated: 2014/02/18 17:05:30 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct		s_lst
{
	char			*line;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_path
{
	char			*path;
	int				size;
	struct s_path	*next;
}					t_path;

typedef struct		s_links
{
	struct s_graph	*link;
	struct s_links	*next;
}					t_links;

typedef struct		s_graph
{
	char			*id;
	t_links			*links;
	int				x;
	int				y;
	int				weight;
	int				ran;
	unsigned char	begin;
	unsigned char	end;
	struct s_graph	*next;
}					t_graph;

typedef struct		s_dat
{
	int				nb;
	t_graph			*graph;
}					t_dat;

t_lst	*ft_getmap(t_lst *map);
t_lst	*ft_getnewlst(t_lst *tail, char	*str);
void	ft_free_map(t_lst *map);
void	ft_parsedat(t_dat *dat, t_lst *map);
void	ft_printmap(t_lst *map);
int		ft_isvalid_link(char *line, t_graph *graph);
int		ft_getlinks(t_lst **map, t_graph **graph);
int		ft_isvalid_id(char *line, t_graph *graph);
int		ft_is_ignored(char *line);
t_graph	*ft_getnewnode(t_graph *graph, char *line, int cmd);
int		graph_is_valid(t_graph *graph);
int		ft_is_link(char *line);
int		ft_check_graph(t_graph *graph);
void	ft_resolve(t_dat *dat);
t_path	*ft_find_ways(t_graph *graph);
t_path	*ft_get_way(t_graph *graph);
t_path	*ft_get_move(t_dat *dat, char *path, t_path *move);
t_path	*ft_move_ant(t_dat *dat, t_path *paths, t_path *move);
int		ft_isconform(char *line);

#endif LEM_IN_H
