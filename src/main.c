/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:25:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/16 13:09:44 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"
#include "utils/string.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define SEC_PER_DAY 86400
#define SEC_PER_HOUR 3600
#define SEC_PER_MIN 60

/* Morning greeting split across several one-line defines for readability */
#define G_MORN_1 "Good morning. To whomsoever this message may concern:"
#define G_MORN_2 " I do hope that you have enjoyed a restful night and that the dawn finds you in excellent spirits."
#define G_MORN_3 " Pray, take a moment for tea and steady reflection on "
#define G_MORN_4 "the tasks ahead. Yours sincerely, A Most Concerned Observer."

/* Afternoon greeting */
#define G_AFT_1 "Good afternoon. Permit me to extend my most earnest wishes that your day's endeavours proceed with worthy purpose and unruffled composure."
#define G_AFT_2 " May a restorative cup of tea and a brief repose sustain you through the remainder of the day."
#define G_AFT_3 " With the highest regard, I remain yours."

/* Evening greeting */
#define G_EVE_1 "Good evening. I trust the day's labours have been met with due diligence and that you may now seek solace in convivial company or quiet contemplation."
#define G_EVE_2 " Allow yourself a well-earned supper and the comfort of a warm brew."
#define G_EVE_3 " Ever respectfully, yours faithfully."

/* Night greeting */
#define G_NITE_1 "Good night. If this missive finds you still awake,"
#define G_NITE_2 " I entreat you to take pity on your constitution and retire for restorative slumber at your earliest convenience."
#define G_NITE_3 " Should you be engaged in scholarly pursuits, do ensure a "
#define G_NITE_4 "kettle is close at hand. Kind regards."

/* Late night greeting - tea-induced insanity */
#define G_LATE_1 " Goodness gracious me, what in the Queen's name are you "
#define G_LATE_2 "doing awake at this ungodly hour?! Have you taken complete leave of your senses?!"
#define G_LATE_3 " The clock has struck an hour most indecent"
#define G_LATE_4 ", and yet here you persist, defying the natural"
#define G_LATE_5 " order of civilised society ! I dare say the tea has gone to your head!"
#define G_LATE_6 " PUT THE BLOODY KETTLE ON THIS INSTANT — brew yourself a proper"
#define G_LATE_7 " English breakfast blend, none of that herbal nonsense —"
#define G_LATE_8 " and compose yourself with some dignity whilst contemplating the utter madness of your nocturnal endeavours!"
#define G_LATE_9 " For heaven's sake, have a biscuit, "
#define G_LATE_10 "collect what remains of your scattered wits, "
#define G_LATE_11 " and retire to your bedchamber before you disgrace yourself further! Cheerio and good riddance to consciousness!"

static void	say_hi(void)
{
	struct timeval	tv;
	long long		sec_of_day;
	const char		*greet = "Hello";
	int				h;

	if (gettimeofday(&tv, NULL) == 0)
	{
		sec_of_day = (long long)tv.tv_sec % (long long)SEC_PER_DAY;
		if (sec_of_day < 0)
			sec_of_day += (long long)SEC_PER_DAY;
		h = (int)(sec_of_day / (long long)SEC_PER_HOUR);
		if (h >= 5 && h < 12)
			greet = G_MORN_1 G_MORN_2 G_MORN_3 G_MORN_4;
		else if (h >= 12 && h < 17)
			greet = G_AFT_1 G_AFT_2 G_AFT_3;
		else if (h >= 17 && h < 21)
			greet = G_EVE_1 G_EVE_2 G_EVE_3;
		else if (h >= 21 && h < 23)
			greet = G_NITE_1 G_NITE_2 G_NITE_3 G_NITE_4;
		else
			greet = G_LATE_1 G_LATE_2 G_LATE_3 G_LATE_4 G_LATE_5 G_LATE_6 G_LATE_7 G_LATE_8 G_LATE_9 G_LATE_10 G_LATE_11;
	}
	printf("%s\n", greet);
}

int	main(int argc, char const *argv[])
{
	t_string	*content;
	t_table		*map;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	say_hi();
	content = string_from_file(argv[1]);
	if (!content)
	{
		fprintf(stderr, "Error: Failed to read map file '%s'\n", argv[1]);
		return (1);
	}
	map = table_load(content->data);
	if (!map)
	{
		string_free(content);
		fprintf(stderr, "Error: Failed to load map\n");
		return (1);
	}
	string_free(content);
	printf("Map loaded successfully: %zux%zu\n", map->width, map->height);
	table_free(map);
	return (0);
}
