
#include "push_swap.h"

void	init(t_vars *vars, int args[], int len)
{
	int	i;

	vars->la = len;
	vars->lb = 0;

	vars->nb = (int *)malloc(sizeof(int) * len);
	vars->na = (int *)malloc(sizeof(int) * len);

	// Make all empty vals to 1010101 so i can be sure if there is
	// an error
	i = 0;
	while (i < vars->la)
	{
		vars->na[i] = args[i];
		vars->nb[i] = 1010101;
		i++;
	}
	render(vars, "init", true);
}

void	test_funcs(t_vars *vars)
{
	sa(vars, true);
	sb(vars, true);
	ss(vars, true);

	pa(vars, true);
	pb(vars, true);

	ra(vars, true);
	rb(vars, true);
	rr(vars, true);

	rra(vars, true);
	rrb(vars, true);
	rrr(vars, true);
}

void	three_sort(t_vars *vars)
{
	bool	top_bigger;
}

int	main(void)
{
	t_vars	vars;

	three_sort(&vars);
	init_cli(&vars);
}
