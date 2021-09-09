/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:40:07 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/09 23:40:31 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MAP_H
# define KEY_MAP_H

/*
** KEYS
*/
# ifdef LINUX
#  define KEY_UP	65362
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  define KEY_DOWN	65364
#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_W		119
#  define KEY_B		98
#  define KEY_C		99
#  define KEY_G		103
#  define KEY_R		114
#  define KEY_ESC	65307
# else
#  define KEY_UP	126
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
#  define KEY_DOWN	125
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_W		13
#  define KEY_B		11
#  define KEY_C		8
#  define KEY_G		5
#  define KEY_R		15
#  define KEY_ESC	53
# endif

/*
** BUTTONS
*/
# define MOUSE_ZOOM_OUT	4
# define MOUSE_ZOOM_IN	5

/*
** X11 EVENTS
*/
# define KEY_PRESS			2
# define KEY_RELEASE		3
# define BTN_PRESS			4
# define BTN_RELEASE		5
# define MOTION_NOTIFY		6
# define ENTER_NOTIFY		7
# define LEAVE_NOTIFY		8
# define FOCUS_IN			9
# define FOCUS_OUT			10
# define KEYMAP_NOTIFY		11
# define EXPOSE				12
# define GRAPHICS_EXPOSE	13
# define NO_EXPOSE			14
# define VISIBILITY_NOTIFY	15
# define CREATE_NOTIFY		16
# define DESTROY_NOTIFY		17
# define UNMAP_NOTIFY		18
# define MAP_NOTIFY			19
# define MAP_REQUEST		20
# define REPARENT_NOTIFY	21
# define CONFIGURE_NOTIFY	22
# define CONFIGURE_REQUEST	23
# define GRAVITY_NOTIFY		24
# define RESIZE_REQUEST		25
# define CIRCULATE_NOTIFY	26
# define CIRCULATE_REQUEST	27
# define PROPERTY_NOTIFY	28
# define SELECTION_CLEAR	29
# define SELECTION_REQUEST	30
# define SELECTION_NOTIFY	31
# define COLORMAP_NOTIFY	32
# define CLIENT_MESSAGE		33
# define MAPPING_NOTIFY		34
# define GENERIC_EVENT		35
# define LAST_EVENT			36

# ifdef LINUX
#  define BTN_X	CLIENT_MESSAGE
# else
#  define BTN_X	DESTROY_NOTIFY
# endif

/*
** X11 MASKS
*/
# define KEY_PRESS_MASK				0
# define KEY_RELEASE_MASK			1
# define BTN_PRESS_MASK				2
# define BTN_RELEASE_MASK			3
# define ENTER_WINDOW_MASK			4
# define LEAVE_WINDOW_MASK			5
# define POINTER_MOTION_MASK		6
# define POINTER_MOTION_HINT_MASK	7
# define BTN1_MOTION_MASK			8
# define BTN2_MOTION_MASK			9
# define BTN3_MOTION_MASK			10
# define BTN4_MOTION_MASK			11
# define BTN5_MOTION_MASK			12
# define BTN_MOTION_MASK			13
# define KEYMAP_STATE_MASK			14
# define EXPOSURE_MASK				15
# define VISIBILITY_CHANGE_MASK		16
# define STRUCTURE_NOTIFY_MASK		17
# define RESIZE_REDIRECT_MASK		18
# define SUBSTRUCTURE_Notify_MASK	19
# define SUBSTRUCTURE_REDIRECT_MASK	20
# define FOCUS_CHANGE_MASK			21
# define PROPERTY_CHANGE_MASK		22
# define COLORMAP_CHANGE_MASK		23
# define OWNER_GRAB_BTN_MASK		24
#endif
