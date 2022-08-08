#include "main.h"

/**
 *
 *
 *
 */
const char *getFlags(const char *ptr, fmt_spec_info *info)
{
	int done = 1;

	while (done)
	{
		switch (*ptr){
		case ' ':
			if (!(info->flags & SPACE))
			{
				info->flags += SPACE;
			}
			info->spec_len += 1;
			ptr++;
			break;

		default:
			done = 0;
		}
	}

	return (ptr);
}

/**
 *
 *
 *
 */
const char *getWidth(const char *ptr, fmt_spec_info *info)
{
	(void) info;
	return (ptr);
}

/**
 *
 *
 *
 */
const char *getPrecision(const char *ptr, fmt_spec_info *info)
{
	(void) info;
	return (ptr);
}

/**
 *
 *
 *
 */
const char *get_len_mod(const char *ptr, fmt_spec_info *info)
{
	(void) info;
	return (ptr);
}

/**
 *
 *
 *
 */
const char *get_conversion(const char *ptr, fmt_spec_info *info)
{
	switch (*ptr)
	{
	case 's':
		info->spec = 's';
		break;
	case 'c':
		info->spec = 'c';
		break;
	case '%':
		info->spec = '%';
		break;
	case 'i':
		info->spec = 'i';
		break;
	case 'd':
		info->spec = 'd';
		break;
	default:
		info->spec = *ptr;
	}
	info->spec_len += 1;
	return (ptr + 1);
}
