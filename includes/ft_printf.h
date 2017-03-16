/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/16 20:42:53 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "color.h"

# define CONVS 	"sSpdDioOuUxXcCbn%"
# define MODIFS "hlhhlljz"
# define FLAGS 	"#0123456789 -+*$L.hlhhlljz"


typedef struct		s_datas
{
	char			*result;
	va_list			ap;
	char			*flags;
	int				*tmp_len;
	int				len;
	int				cplen;
	int				un_ord;
	int				pointer;
}					t_datas;

typedef struct		s_flags
{
	int				dollar;
	int				precision;
	int				less;
	int				zero;
	int				diese;
	int				plus;
	int				space;
	int				padding;
}					t_flags;

int					ft_printf(const char *buff, ...);
int					ft_datas_init(t_datas *datas, char *buff);
int					ft_launch_process(t_datas *datas, char *buff);
t_list				*ft_get_argslist(t_datas *datas, char *buff);
int					ft_get_arg(t_datas *datas, char *buff, size_t *ci, t_list **lst);
int					verif_dollar(t_list **tmp, char *fstr, int dollar);
int					verif_dollar_star(t_list **tmp, char *fstr, size_t conv_index);
int					ft_get_option(t_list **tmp, int stars, int option, t_datas *datas);
char				*ft_get_unconvdatas(t_datas *datas, char *buff, size_t i);
char				*ft_exit(t_datas *datas);
char				*ft_exit_conv(t_datas *datas, char *argcvd);
char				*ft_fill_buff(t_datas *datas, char *buff);
char				*ft_get_convdatas(t_datas *datas, char *buff);
char				*ft_get_lastdatas(t_datas *datas, char *buff);
int					ft_flags_init(t_datas *datas, t_flags *flags);
int					ft_get_star_arg(t_datas *datas, size_t conv_index, char *buff, t_list **tmp);
int					ft_list_dont_exist(t_datas *datas, size_t conv_index, char *buff, t_list **tmp);
int					ft_list_exist(t_datas *datas, size_t conv_index, char *buff, t_list **tmp);

//get conv from va_list
char				*ft_get_s_conv(t_datas *datas);
char				*ft_get_ls_conv(t_datas *datas);
char				*ft_get_p_conv(t_datas *datas);
char				*ft_get_d_conv(t_datas *datas);
char				*ft_get_ld_conv(t_datas *datas);
char				*ft_get_i_conv(t_datas *datas);
char				*ft_get_o_conv(t_datas *datas);
char				*ft_get_lo_conv(t_datas *datas);
char				*ft_get_u_conv(t_datas *datas);
char				*ft_get_lu_conv(t_datas *datas);
char				*ft_get_x_conv(t_datas *datas);
char				*ft_get_lx_conv(t_datas *datas);
char				*ft_get_x_conv(t_datas *datas);
char				*ft_get_lx_conv(t_datas *datas);
char				*ft_get_c_conv(t_datas *datas);
char				*ft_get_lc_conv(t_datas *datas);
char				*ft_get_b_conv(t_datas *datas);
char				*ft_get_n_conv(t_datas *datas);
char				*ft_get_percent_conv(t_datas *datas);

typedef	char		*(*t_get_convs)(t_datas *datas);

//int					ft_get_num(char *flags, t_datas *datas, size_t *i);	

// get flags from const char
int					ft_space(t_datas *datas, char *strflag, t_flags *flags, size_t *i);
int					ft_plus(t_datas *datas, char *strflag, t_flags *flags, size_t *i);
int					ft_diese(t_datas *datas, char *strflag, t_flags *flags, size_t *i);
int					ft_zero(t_datas *datas, char *strflag, t_flags *flags, size_t *i);
int					ft_less(t_datas *datas, char *strflag, t_flags *flags, size_t *i);
int					ft_precision(t_datas *datas, char *strflag, t_flags *flags, size_t *i);
int					ft_arg_precision(t_datas *datas, char *strflag, t_flags *flags, size_t *i);
int					ft_n_arg_precision(t_datas *datas, int n, t_flags *flags, size_t *i);
int					ft_padding(t_datas *datas, char *strflag, t_flags *flags, size_t *i);
int					ft_arg_padding(t_datas *datas, char *strflag, t_flags *flags, size_t *i);
int					ft_n_arg_padding(t_datas *datas, int n, t_flags *flags, size_t *i);

typedef	int			(*t_get_flags)(t_datas *datas, char *strflag, t_flags *flags, size_t *i);


// ====================================== d / nums functions =============================
int					ft_d_space(char **argcvd, t_datas *datas, t_flags *flags);
int					ft_d_zero(char **argcvd, t_datas *datas, t_flags *flags);
int					ft_d_plus(char **argcvd, t_datas *datas, t_flags *flags);
int					ft_d_precision(char **argcvd, t_datas *datas, t_flags *flags);
int					ft_d_padding(char **argcvd, t_datas *datas, t_flags *flags);
int					ft_n_d(t_datas *datas, t_flags *flags);

// ====================================== o functions ====================================
int					ft_o_diese(char **argcvd, t_datas *datas, t_flags *flags);

// ====================================== u functions ====================================
unsigned int		ft_n_u(t_datas *datas, t_flags *flags);
unsigned long int	ft_n_lu(t_datas *datas, t_flags *flags);

// ====================================== x functions ====================================
int					ft_x_diese(char **argcvd, t_datas *datas, t_flags *flags);
int					ft_lx_diese(char **argcvd, t_datas *datas, t_flags *flags);

// ====================================== c functions ====================================
void				ft_aff_nulchar(t_datas *datas);
void				ft_aff_nulchar_clean(t_datas *datas);
char				*ft_launch_c_flags(char **argcvd, t_datas *datas, t_flags *flags);
int					ft_c_zero(char **argcvd, t_datas *datas, t_flags *flags);
int					ft_c_precision(char **argcvd, t_datas *datas, t_flags *flags);

// ====================================== s functions ====================================
char				*ft_n_s(t_datas *datas, t_flags *flags);
int					ft_s_precision(char **argcvd, t_datas *datas, t_flags *flags);
int					ft_ls_precision(char **argcvd, t_datas *datas, t_flags *flags);
typedef int			(*t_flags_func)(char **argcvd, t_datas *datas, t_flags *flags);


#endif
