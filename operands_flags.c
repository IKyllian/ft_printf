#include "ft_printf.h"

void	operands_dot(t_struct flags, int *count, int arg, int argc_length)
{
	if (flags.has_dot && !flags.has_negative)
	{
		if (arg < 0)
				flags.dot_value -= 1;
		if (flags.has_multiple && flags.dot_value > flags.has_multiple)
			ft_fill_space(' ', (flags.dot_value - flags.has_multiple), count);
		else if (!flags.has_multiple)
		{
			if (flags.spaces_number >= argc_length)
			{
				if ((flags.dot_value - flags.spaces_number) > 0)
					ft_fill_space(' ', (flags.dot_value - flags.spaces_number), count);
			}
			else
				if ((flags.dot_value - argc_length) > 0)
					ft_fill_space(' ', (flags.dot_value - argc_length), count);
		}
	}
}

void	operands_spaces_prefix(t_struct flags, int *count, int arg, int argc_length)
{
	if (flags.has_multiple)
	{
		if (arg < 0)
		{
			if (!flags.has_dot)
				flags.has_multiple -= 1;
			ft_putchar('-', count);
		}
		if ((flags.has_zero && !flags.has_negative) || flags.dot_value)
			ft_fill_space('0', (flags.has_multiple - argc_length), count);
		else if (!flags.has_negative)
			ft_fill_space(' ', (flags.has_multiple - argc_length), count);
	}
	else if ((flags.spaces_number && !flags.has_negative && !flags.has_multiple && flags.spaces_number > argc_length)
			|| (flags.spaces_number && flags.has_negative && flags.dot_value) )
	{
		if (arg < 0)
			ft_putchar('-', count);
		if (flags.has_zero || flags.dot_value)
			ft_fill_space('0', (flags.spaces_number - argc_length), count);
		else
			ft_fill_space(' ', (flags.spaces_number - argc_length), count);
	}
	else if (arg < 0)
		ft_putchar('-', count);
}

void	operands_spaces_suffix(t_struct flags, int *count, int arg, int argc_length)
{
	if (flags.spaces_number && flags.has_negative && !flags.has_dot)
		ft_fill_space(' ', (flags.spaces_number - argc_length), count);
	else if (flags.has_multiple && flags.has_negative && !flags.has_dot)
		ft_fill_space(' ', (flags.has_multiple - argc_length), count);
	else if (flags.has_negative && flags.has_dot && !flags.dot_value)
		ft_fill_space('0', (flags.spaces_number - argc_length), count);
	else if (flags.has_negative && flags.dot_value && !flags.has_multiple)
	{
		if (flags.spaces_number < argc_length)
			flags.spaces_number = argc_length;
		if (arg < 0)
			flags.dot_value -= 1;
		if ((flags.dot_value - flags.spaces_number) > 0)
			ft_fill_space(' ', (flags.dot_value - flags.spaces_number), count);
	}
	else if (flags.has_negative && flags.dot_value && flags.has_multiple)
	{
		if (flags.has_multiple < argc_length)
			flags.has_multiple = argc_length;
		
		if ((flags.dot_value - flags.has_multiple) > 0)
			ft_fill_space(' ', (flags.dot_value - flags.has_multiple), count);
	}
}