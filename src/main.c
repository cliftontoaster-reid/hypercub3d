/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbores <mbores@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:25:00 by lfiorell          #+#    #+#             */
/*   Updated: 2025/12/17 16:58:25 by mbores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/table.h"
#include "map/minimap.h"
#include "utils/string.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define SEC_PER_DAY 86400
#define SEC_PER_HOUR 3600
#define SEC_PER_MIN 60

/* Morning greeting split across several one-line defines for readability */
#define G_MORN_1 "Good morning. To whomsoever this most courteous missive may concern, "
#define G_MORN_2 "I do sincerely trust that Morpheus has treated you kindly "
#define G_MORN_3 "and that you rise neither bleary of eye nor fragile of constitution. "
#define G_MORN_4 "Pray, before you embark upon the manifold burdens of the day, "
#define G_MORN_5 "take a moment to put the kettle on, warm the pot like a civilised soul, "
#define G_MORN_6 "and contemplate your itinerary over a properly brewed cup of tea. "
#define G_MORN_7 "Do resist, I beg of you, the barbaric temptation of instant granules, "
#define G_MORN_8 "for such things are an affront to decency and good taste. "
#define G_MORN_9 "May your toast be evenly browned, your marmalade uncommonly zesty, "
#define G_MORN_10 "and your timetable only moderately absurd. "
#define G_MORN_11 "Yours, with the most genteel encouragement for the hours ahead."

/* Afternoon greeting */
#define G_AFT_1 "Good afternoon. Permit me, if you would be so kind, "
#define G_AFT_2 "to extend my most earnest hopes that your day's endeavours proceed "
#define G_AFT_3 "with tolerable order and only the faintest hint of chaos. "
#define G_AFT_4 "By this respectable hour, one really ought to have secured at least one respectable cup of tea, "
#define G_AFT_5 "a biscuit of sound moral character, and a chair that does not actively conspire against one's posture. "
#define G_AFT_6 "Should the burdens of labour weigh heavily upon your shoulders, do consider the restorative powers "
#define G_AFT_7 "of a brief pause, a deep sigh, and a top-up of your favourite blend. "
#define G_AFT_8 "Let no officious timetable or impudent deadline deprive you of a proper break, "
#define G_AFT_9 "for even Her Majesty's most industrious subjects are entitled to a quiet moment with the biscuit tin. "
#define G_AFT_10 "May your remaining tasks prove tractable, your colleagues only mildly unreasonable, "
#define G_AFT_11 "and your afternoon commute mercifully uneventful. With the highest regard, I remain yours."

/* Evening greeting */
#define G_EVE_1 "Good evening. I trust that the day's labours, however ill-advised or enthusiastically embraced, "
#define G_EVE_2 "have been met with due diligence and at least a modicum of triumph. "
#define G_EVE_3 "Now, as the sun takes its leave and the sky dons its more contemplative hues, "
#define G_EVE_4 "you are hereby granted moral permission to abandon productivity in favour of comfort. "
#define G_EVE_5 "Do gather your wits from whatever office floor, lecture hall, or public transport they have been scattered upon, "
#define G_EVE_6 "and proceed directly to a seat of reasonable softness. "
#define G_EVE_7 "A well-portioned supper, a steaming vessel of tea, and perhaps a biscuit of unashamed indulgence "
#define G_EVE_8 "are not merely recommended; they are, in point of fact, your solemn duty. "
#define G_EVE_9 "Should you be among those curious souls who elect to continue working at this hour, "
#define G_EVE_10 "kindly be advised that such behaviour is being observed with polite concern and the occasional disapproving tut. "
#define G_EVE_11 "May your evening be calm, your surroundings cosy, and your tea never left to grow tragically lukewarm."

/* Night greeting */
#define G_NITE_1 "Good night. If this most gentle communiqué finds you still awake when respectable folk are already contemplating tomorrow's breakfast, "
#define G_NITE_2 "one must raise a delicately arched eyebrow. "
#define G_NITE_3 "I entreat you, with all the quiet urgency of a long-suffering nanny, "
#define G_NITE_4 "to take pity on your weary frame and consider the radical notion of going to bed at a sensible hour. "
#define G_NITE_5 "Should you be engaged in earnest study, arcane computation, or some manner of artistic torment, "
#define G_NITE_6 "do at the very least ensure that a kettle is nearby and that your teapot is not left scandalously empty. "
#define G_NITE_7 "Remember that even the stoutest constitution requires a decent interval of unconsciousness "
#define G_NITE_8 "if it is to face the morrow with anything resembling grace. "
#define G_NITE_9 "Take this, then, as a kindly meant but unmistakably pointed suggestion to close your books, "
#define G_NITE_10 "silence your devices, and shuffle bedwards with as much dignity as you can muster whilst clutching a final, consoling brew. "
#define G_NITE_11 "Kind regards, and may your dreams be mercifully free of missed trains, awkward small talk, and forgotten passwords."

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
			greet = G_MORN_1 G_MORN_2 G_MORN_3 G_MORN_4 G_MORN_5 G_MORN_6 G_MORN_7 G_MORN_8 G_MORN_9 G_MORN_10 G_MORN_11;
		else if (h >= 12 && h < 17)
			greet = G_AFT_1 G_AFT_2 G_AFT_3 G_AFT_4 G_AFT_5 G_AFT_6 G_AFT_7 G_AFT_8 G_AFT_9 G_AFT_10 G_AFT_11;
		else if (h >= 17 && h < 21)
			greet = G_EVE_1 G_EVE_2 G_EVE_3 G_EVE_4 G_EVE_5 G_EVE_6 G_EVE_7 G_EVE_8 G_EVE_9 G_EVE_10 G_EVE_11;
		else if (h >= 21 && h < 23)
			greet = G_NITE_1 G_NITE_2 G_NITE_3 G_NITE_4 G_NITE_5 G_NITE_6 G_NITE_7 G_NITE_8 G_NITE_9 G_NITE_10 G_NITE_11;
		else
			greet = G_LATE_1 G_LATE_2 G_LATE_3 G_LATE_4 G_LATE_5 G_LATE_6 G_LATE_7 G_LATE_8 G_LATE_9 G_LATE_10 G_LATE_11;
	}
	printf("%s\n", greet);
}

int	main(int argc, char const *argv[])
{
	t_string	*content;
	t_table		*map;
	t_window	*window;
	t_holy_cow	*all;

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
	window = malloc(sizeof(t_window));
	all = malloc(sizeof(t_holy_cow));
	all->map = map;
	all->window = window;
	all->content = content;
	printf("Map loaded successfully: %zux%zu\n", map->width, map->height);
	init_window(all);
	// table_free(map);
	return (0);
}
