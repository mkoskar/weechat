/*
 * Copyright (c) 2003 by FlashCode <flashcode@flashtux.org>
 *                       Bounga <bounga@altern.org>
 *                       Xahlexx <xahlexx@tuxisland.org>
 * See README for License detail.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


/* gui-display.c: display functions for Gtk GUI */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>

#include "../../weechat.h"
#include "../gui.h"
#include "../../config.h"
#include "../../irc/irc.h"


t_gui_color gui_colors[] =
{ { "default", 0 },
  { "black", 0 },
  { "red", 0 },
  { "lightred", 0 },
  { "green", 0 },
  { "lightgreen", 0 },
  { "brown", 0 },
  { "yellow", 0 },
  { "blue", 0 },
  { "lightblue", 0 },
  { "magenta", 0L },
  { "lightmagenta", 0 },
  { "cyan", 0 },
  { "lightcyan", 0 },
  { "gray", 0 },
  { "white", 0 },
  { NULL, 0 }
};

char *nicks_colors[COLOR_WIN_NICK_NUMBER] =
{ "cyan", "magenta", "green", "brown", "lightblue", "gray",
  "lightcyan", "lightmagenta", "lightgreen", "blue" };

int color_attr[NUM_COLORS];

GtkWidget *gtk_main_window;


/*
 * gui_assign_color: assign a color (read from config)
 */

int
gui_assign_color (int *color, char *color_name)
{
    int i;
    
    /* look for Gtk colors in table */
    i = 0;
    while (gui_colors[i].name)
    {
        if (strcasecmp (gui_colors[i].name, color_name) == 0)
        {
            *color = gui_colors[i].color;
            return 1;
        }
        i++;
    }
    
    /* color not found */
    return 0;
}

/*
 * gui_get_color_by_name: get color by name
 */

int
gui_get_color_by_name (char *color_name)
{
    int i;
    
    /* look for Gtk in table */
    i = 0;
    while (gui_colors[i].name)
    {
        if (strcasecmp (gui_colors[i].name, color_name) == 0)
            return gui_colors[i].color;
        i++;
    }
    
    /* color not found */
    return -1;
}

/*
 * gui_get_color_by_value: get color name by value
 */

char *
gui_get_color_by_value (int color_value)
{
    int i;
    
    /* look for Gtk colors in table */
    i = 0;
    while (gui_colors[i].name)
    {
        if (gui_colors[i].color == color_value)
            return gui_colors[i].name;
        i++;
    }
    
    /* color not found */
    return NULL;
}

/*
 * gui_calculate_pos_size: calculate position and size for a window & sub-win
 */

void
gui_calculate_pos_size (t_gui_window *window)
{
    /* TODO: write gui_calculate_pos_size for Gtk GUI */
    (void) window;
}

/*
 * gui_draw_window_title: draw title window
 */

void
gui_draw_window_title (t_gui_window *window)
{
    char format[32];
    
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    if (CHANNEL(window))
    {
        sprintf (format, "%%-%ds", window->win_width);
        /* TODO: display topic */
    }
    else
    {
        /* TODO: display title for server window */
    }
}

/*
 * gui_redraw_window_title: redraw title window
 */

void
gui_redraw_window_title (t_gui_window *window)
{
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    /* TODO: first delete window content */
    gui_draw_window_title (window);
}

/*
 * gui_get_line_num_splits: returns number of lines on window
 *                          (depending on window width and type (server/channel)
 *                          for alignment)
 */

int
gui_get_line_num_splits (t_gui_window *window, t_gui_line *line)
{
    int length, width;
    
    /* TODO: modify arbitraty value for non aligning messages on time/nick? */
    if (line->length_align >= window->win_chat_width - 5)
    {
        length = line->length;
        width = window->win_chat_width;
    }
    else
    {
        length = line->length - line->length_align;
        width = window->win_chat_width - line->length_align;
    }
    
    return (length % width == 0) ? (length / width) : ((length / width) + 1);
}

/*
 * gui_display_end_of_line: display end of a line in the chat window
 */

void
gui_display_end_of_line (t_gui_window *window, t_gui_line *line, int count)
{
    /* TODO: display end of line! */
    (void) window;
    (void) line;
    (void) count;
}

/*
 * gui_display_line: display a line in the chat window
 *                   if stop_at_end == 1, screen will not scroll and then we
 *                   exit since chat window is full
 *                   returns: 1 if stop_at_end == 0 or screen not full
 *                            0 if screen is full and if stop_at_end == 1
 */

int
gui_display_line (t_gui_window *window, t_gui_line *line, int stop_at_end)
{
    /* TODO: display line! */
    (void) window;
    (void) line;
    (void) stop_at_end;
    return 1;
}

/*
 * gui_draw_window_chat: draw chat window
 */

void
gui_draw_window_chat (t_gui_window *window)
{
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    /* TODO: draw chat window */
}

/*
 * gui_redraw_window_chat: redraw chat window
 */

void
gui_redraw_window_chat (t_gui_window *window)
{
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    /* TODO: first delete window content */
    gui_draw_window_chat (window);
}

/*
 * gui_draw_window_nick: draw nick window
 */

void
gui_draw_window_nick (t_gui_window *window)
{
    int i, x, y, column, max_length;
    char format[32];
    t_irc_nick *ptr_nick;
    
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    if (CHANNEL(window) && CHANNEL(window)->nicks)
    {
        max_length = nick_get_max_length (CHANNEL(window));
        if ((window == gui_current_window) &&
            ((max_length + 2) != window->win_nick_width))
        {
            /* TODO: auto resize nicklist and chat windows */
        }
        sprintf (format, "%%-%ds", max_length);
            
        switch (cfg_look_nicklist_position)
        {
            case CFG_LOOK_NICKLIST_LEFT:
                /* TODO: init nicklist (left) */
                break;
            case CFG_LOOK_NICKLIST_RIGHT:
                /* TODO: init nicklist (right) */
                break;
            case CFG_LOOK_NICKLIST_TOP:
                /* TODO: init nicklist (top) */
                break;
            case CFG_LOOK_NICKLIST_BOTTOM:
                /* TODO: init nicklist (bottom) */
                break;
        }
        /* TODO: draw nicklist! */
        (void) i;
        (void) x;
        (void) y;
        (void) column;
        (void) ptr_nick;
    }
}

/*
 * gui_redraw_window_nick: redraw nick window
 */

void
gui_redraw_window_nick (t_gui_window *window)
{
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    /* TODO: first delete window content */
    gui_draw_window_nick (window);
}

/*
 * gui_draw_window_status: draw status window
 */

void
gui_draw_window_status (t_gui_window *window)
{
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    /* TODO: draw status window! */
}

/*
 * gui_redraw_window_status: redraw status window
 */

void
gui_redraw_window_status (t_gui_window *window)
{
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    /* TODO: first delete window content */
    gui_draw_window_status (window);
}

/*
 * gui_draw_window_input: draw input window
 */

void
gui_draw_window_input (t_gui_window *window)
{
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    /* TODO: draw input window */
}

/*
 * gui_redraw_window_input: redraw input window
 */

void
gui_redraw_window_input (t_gui_window *window)
{
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    /* TODO: first delete window content */
    gui_draw_window_input (window);
}

/*
 * gui_redraw_window: redraw a window
 */

void
gui_redraw_window (t_gui_window *window)
{
    /* TODO: manage splitted windows! */
    if (window != gui_current_window)
        return;
    
    gui_redraw_window_title (window);
    gui_redraw_window_chat (window);
    if (window->win_nick)
        gui_redraw_window_nick (window);
    gui_redraw_window_status (window);
    gui_redraw_window_input (window);
}

/*
 * gui_switch_to_window: switch to another window
 */

void
gui_switch_to_window (t_gui_window *window)
{
    int another_window;
    t_gui_window *ptr_win;
    
    another_window = 0;
    for (ptr_win = gui_windows; ptr_win; ptr_win = ptr_win->next_window)
    {
        if (ptr_win->win_title)
        {
            /* TODO: manage splitted windows */
            another_window = 1;
            window->win_title = ptr_win->win_title;
            window->win_chat = ptr_win->win_chat;
            window->win_nick = ptr_win->win_nick;
            window->win_status = ptr_win->win_status;
            window->win_input = ptr_win->win_input;
            ptr_win->win_title = NULL;
            ptr_win->win_chat = NULL;
            ptr_win->win_nick = NULL;
            ptr_win->win_status = NULL;
            ptr_win->win_input = NULL;
            break;
        }
    }
    
    gui_calculate_pos_size (window);
    
    /* first time creation for windows */
    if (!another_window)
    {
        /* create new windows */
        /* TODO: create title, chat, nick, status and input windows */
    }
    else
    {
        /* create chat & nick windows */
        if (WIN_IS_CHANNEL(window))
        {
            /* (re)create nicklist window */
            /* TODO: delete nick/chat windows and create them */
        }
        if (!(WIN_IS_CHANNEL(window)))
        {
            /* remove nick list window */
            /* TODO: remove nicklist window and create full chat window */
        }
    }
    
    /* change current window to the new window */
    gui_current_window = window;
    
    window->unread_data = 0;
}

/*
 * gui_switch_to_previous_window: switch to previous window
 */

void
gui_switch_to_previous_window ()
{
    /* if only one windows then return */
    if (gui_windows == last_gui_window)
        return;
    
    if (gui_current_window->prev_window)
        gui_switch_to_window (gui_current_window->prev_window);
    else
        gui_switch_to_window (last_gui_window);
    gui_redraw_window (gui_current_window);
}

/*
 * gui_switch_to_next_window: switch to next window
 */

void
gui_switch_to_next_window ()
{
    /* if only one windows then return */
    if (gui_windows == last_gui_window)
        return;
    
    if (gui_current_window->next_window)
        gui_switch_to_window (gui_current_window->next_window);
    else
        gui_switch_to_window (gui_windows);
    gui_redraw_window (gui_current_window);
}

/*
 * gui_move_page_up: display previous page on window
 */

void
gui_move_page_up ()
{
    if (!gui_current_window->first_line_displayed)
    {
        gui_current_window->sub_lines += gui_current_window->win_chat_height - 1;
        gui_redraw_window_chat (gui_current_window);
        gui_redraw_window_status (gui_current_window);
    }
}

/*
 * gui_move_page_down: display next page on window
 */

void
gui_move_page_down ()
{
    if (gui_current_window->sub_lines > 0)
    {
        gui_current_window->sub_lines -= gui_current_window->win_chat_height - 1;
        if (gui_current_window->sub_lines < 0)
            gui_current_window->sub_lines = 0;
        if (gui_current_window->sub_lines == 0)
            gui_current_window->unread_data = 0;
        gui_redraw_window_chat (gui_current_window);
        gui_redraw_window_status (gui_current_window);
    }
}

/*
 * gui_gtk_resize_handler: called when term size is modified
 */

void
gui_gtk_resize_handler ()
{
    /* TODO: write resize handler for Gtk */
}

/*
 * gui_init_colors: init GUI colors
 */

void
gui_init_colors ()
{
    /* TODO: init colors for Gtk */
}

/*
 * gui_init: init GUI
 */

void
gui_init ()
{
    GtkWidget *vbox1;
    GtkWidget *entry_topic;
    GtkWidget *notebook1;
    GtkWidget *vbox2;
    GtkWidget *hbox1;
    GtkWidget *scrolledwindow_chat;
    GtkWidget *textview_chat;
    GtkWidget *scrolledwindow_nick;
    GtkWidget *textview_nick;
    GtkWidget *entry_input;
    GtkWidget *label1;
    
    gtk_main_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (gtk_main_window), WEECHAT_NAME_AND_VERSION);
    
    vbox1 = gtk_vbox_new (FALSE, 0);
    gtk_widget_show (vbox1);
    gtk_container_add (GTK_CONTAINER (gtk_main_window), vbox1);
    
    entry_topic = gtk_entry_new ();
    gtk_widget_show (entry_topic);
    gtk_box_pack_start (GTK_BOX (vbox1), entry_topic, FALSE, FALSE, 0);
    
    notebook1 = gtk_notebook_new ();
    gtk_widget_show (notebook1);
    gtk_box_pack_start (GTK_BOX (vbox1), notebook1, TRUE, TRUE, 0);
    gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook1), GTK_POS_BOTTOM);
    
    vbox2 = gtk_vbox_new (FALSE, 0);
    gtk_widget_show (vbox2);
    gtk_container_add (GTK_CONTAINER (notebook1), vbox2);
    
    hbox1 = gtk_hbox_new (FALSE, 0);
    gtk_widget_show (hbox1);
    gtk_box_pack_start (GTK_BOX (vbox2), hbox1, TRUE, TRUE, 0);
    
    scrolledwindow_chat = gtk_scrolled_window_new (NULL, NULL);
    gtk_widget_show (scrolledwindow_chat);
    gtk_box_pack_start (GTK_BOX (hbox1), scrolledwindow_chat, TRUE, TRUE, 0);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow_chat), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
    
    textview_chat = gtk_text_view_new ();
    gtk_widget_show (textview_chat);
    gtk_container_add (GTK_CONTAINER (scrolledwindow_chat), textview_chat);
    gtk_widget_set_size_request (textview_chat, 300, -1);
    gtk_text_view_set_editable (GTK_TEXT_VIEW (textview_chat), FALSE);
    gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (textview_chat), FALSE);
    
    scrolledwindow_nick = gtk_scrolled_window_new (NULL, NULL);
    gtk_widget_show (scrolledwindow_nick);
    gtk_box_pack_start (GTK_BOX (hbox1), scrolledwindow_nick, TRUE, TRUE, 0);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow_nick), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
    
    textview_nick = gtk_text_view_new ();
    gtk_widget_show (textview_nick);
    gtk_container_add (GTK_CONTAINER (scrolledwindow_nick), textview_nick);
    gtk_text_view_set_editable (GTK_TEXT_VIEW (textview_nick), FALSE);
    gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (textview_nick), FALSE);
    
    entry_input = gtk_entry_new ();
    gtk_widget_show (entry_input);
    gtk_box_pack_start (GTK_BOX (vbox2), entry_input, FALSE, FALSE, 0);
    
    label1 = gtk_label_new (_("server"));
    gtk_widget_show (label1);
    gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 0), label1);
    gtk_label_set_justify (GTK_LABEL (label1), GTK_JUSTIFY_LEFT);
    
    gtk_widget_show_all (gtk_main_window);
    
    /* TODO: set gui_ready to 1 when Gtk display functions will be ok */
    gui_ready = 0;
}

/*
 * gui_end: GUI end
 */

void
gui_end ()
{
    t_gui_window *ptr_win;
    
    /* delete all windows */
    for (ptr_win = gui_windows; ptr_win; ptr_win = ptr_win->next_window)
    {
        /* TODO: delete Gtk windows */
        /* TODO: free input buffer, lines, messages, completion */
    }
}

/*
 * gui_add_message: add a message to a window
 */

void
gui_add_message (t_gui_window *window, int type, int color, char *message)
{
    char *pos;
    int length;
    
    /* create new line if previous was ending by '\n' (or if 1st line) */
    if (window->line_complete)
    {
        window->line_complete = 0;
        if (!gui_new_line (window))
            return;
    }
    if (!gui_new_message (window))
        return;
    
    window->last_line->last_message->type = type;
    window->last_line->last_message->color = color;
    pos = strchr (message, '\n');
    if (pos)
    {
        pos[0] = '\0';
        window->line_complete = 1;
    }
    window->last_line->last_message->message = strdup (message);
    length = strlen (message);
    window->last_line->length += length;
    if (type == MSG_TYPE_MSG)
        window->last_line->line_with_message = 1;
    if ((type == MSG_TYPE_TIME) || (type == MSG_TYPE_NICK))
        window->last_line->length_align += length;
    if (pos)
    {
        pos[0] = '\n';
        if ((window == gui_current_window) && (window->sub_lines == 0))
        {
            if ((window->win_chat_cursor_y
                + gui_get_line_num_splits (window, window->last_line)) >
                (window->win_chat_height - 1))
                gui_draw_window_chat (window);
            else
                gui_display_line (window, window->last_line, 1);
        }
        if ((window != gui_current_window) || (window->sub_lines > 0))
        {
            window->unread_data = 1 + window->last_line->line_with_message;
            gui_redraw_window_status (gui_current_window);
        }
    }
}

/*
 * gui_printf_color_type: display a message in a window
 */

void
gui_printf_color_type (t_gui_window *window, int type, int color, char *message, ...)
{
    static char buffer[8192];
    char timestamp[16];
    char *pos;
    va_list argptr;
    static time_t seconds;
    struct tm *date_tmp;

    /* make gcc hapy */
    (void) window;
    (void) type;
    (void) color;
    (void) message;
    
    va_start (argptr, message);
    vsnprintf (buffer, sizeof (buffer) - 1, message, argptr);
    va_end (argptr);
    
    if (gui_ready)
    {
        seconds = time (NULL);
        date_tmp = localtime (&seconds);
        
        pos = buffer - 1;
        while (pos)
        {
            /* TODO: read timestamp format from config! */
            if ((!window->last_line) || (window->line_complete))
            {
                gui_add_message (window, MSG_TYPE_TIME, COLOR_WIN_CHAT_DARK, "[");
                sprintf (timestamp, "%02d", date_tmp->tm_hour);
                gui_add_message (window, MSG_TYPE_TIME, COLOR_WIN_CHAT_TIME, timestamp);
                gui_add_message (window, MSG_TYPE_TIME, COLOR_WIN_CHAT_TIME_SEP, ":");
                sprintf (timestamp, "%02d", date_tmp->tm_min);
                gui_add_message (window, MSG_TYPE_TIME, COLOR_WIN_CHAT_TIME, timestamp);
                gui_add_message (window, MSG_TYPE_TIME, COLOR_WIN_CHAT_TIME_SEP, ":");
                sprintf (timestamp, "%02d", date_tmp->tm_sec);
                gui_add_message (window, MSG_TYPE_TIME, COLOR_WIN_CHAT_TIME, timestamp);
                gui_add_message (window, MSG_TYPE_TIME, COLOR_WIN_CHAT_DARK, "] ");
            }
            gui_add_message (window, type, color, pos+1);
            pos = strchr (pos+1, '\n');
            if (pos)
                if (pos[1] == '\0')
                    pos = NULL;
        }
    }
    else
        g_print ("%s", buffer);
}
