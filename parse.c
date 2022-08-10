#include "main.h"

/**
 *
 *
 *
 */
unsigned int put_into_buffer(char *buffer, unsigned int nextPos, char c)
{
	if (nextPos == 1024)
	{
		write(STDOUT_FILENO, buffer, nextPos);
		nextPos = 0;
	}
	buffer[nextPos] = c;
	return (nextPos + 1);
}

/**
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	va_list list;
	char buffer[1024], *str;
	unsigned int buff_pointer = 0, printed = 0;
	fmt_spec_info *fmt_info;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{

			fmt_info = spec_parser(format + 1);
			if (fmt_info == NULL)
				return (-1);
			str = spec_handler(list,fmt_info);
			if (str == NULL)
			{
				if (fmt_info->spec == '\0')
				{
					free(fmt_info);
					write(STDOUT_FILENO, buffer, buff_pointer);
					return (-1);
				}
				buff_pointer = put_into_buffer(
					buffer, buff_pointer,*format);
				printed += 1;

				if (fmt_info->flags)
				{
					if (fmt_info->flags & HASH)
					{
						buff_pointer = put_into_buffer(
							buffer, buff_pointer,'#');
						printed += 1;
					}
					if (fmt_info->flags & PLUS)
					{
						buff_pointer = put_into_buffer(
							buffer, buff_pointer,'+');
						printed += 1;
					}
					else if (fmt_info->flags & SPACE)
					{
						buff_pointer = put_into_buffer(
							buffer, buff_pointer,' ');
						printed += 1;
					}
					if (fmt_info->flags & DASH)
					{
						buff_pointer = put_into_buffer(
							buffer, buff_pointer,'-');
						printed += 1;
					}
					else if (fmt_info->flags & ZERO)
					{
						buff_pointer = put_into_buffer(
							buffer, buff_pointer,'0');
						printed += 1;
					}
					format += (fmt_info->spec_len - 1);
				}
			}
			else
			{
				buff_pointer = put_into_buffer_str(
					buffer, buff_pointer, str);
				printed += str_len(str);
				if (fmt_info->spec == 'c' && *str == '\0')
				{
					buff_pointer = put_into_buffer(buffer, buff_pointer, '\0');
					printed += 1;
				}
				format += fmt_info->spec_len;
				free(str);
			}
			free(fmt_info);

		}
		else
		{
			buff_pointer = put_into_buffer(buffer, buff_pointer,
						       *format);
			printed +=  1;
		}
		format++;
	}
	write(STDOUT_FILENO, buffer, buff_pointer);
	va_end(list);

	return (printed);
}

/**
 *
 *
 *
 */
fmt_spec_info *spec_parser(const char *ptr)
{
	fmt_spec_info *info;

	info = malloc(sizeof(fmt_spec_info));
	if (info == NULL)
		return (NULL);
	info->spec = '\0';
	info->width = 0;
	info ->precision = 0;
	info->is_width_prec = '\0';
	info->type = '\0';
	info->flags = '\0';
	info->spec_len = 0;

	ptr = getFlags(ptr, info);
	ptr = getWidth(ptr, info);
	ptr = getPrecision(ptr, info);
	ptr = get_len_mod(ptr, info);
	ptr = get_conversion(ptr,info);
	return (info);
}

/**
 *
 *
 *
 *
 */
char *spec_handler(va_list list, fmt_spec_info *info)
{
	fmt_spec_func fun_list[] ={
		{'s', s_to_str},
		{'c', c_to_str},
		{'%', perc_to_str},
		{'d', di_to_str},
		{'i', di_to_str},
		{'b', b_to_str},
		{'u', u_to_str},
		{'o', o_to_str},
		{'x', x_to_str},
		{'X', X_to_str},
		{'\0', NULL}
	};
	int x;

	for (x = 0; x < 10; x++)
	{
		if (info->spec == fun_list[x].c)
		{
			break;
		}
	}
	if (fun_list[x].fun == NULL)
		return (NULL);
	else
		return (*fun_list[x].fun)(list, info);
}
