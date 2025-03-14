/*
	Copyright (c) 2017-2020 ByteBit

	This file is part of BetterSpades.

	BetterSpades is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	BetterSpades is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with BetterSpades.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>

#include "list.h"

struct config_file_entry {
	char section[32];
	char name[32];
	char value[32];
};

extern struct RENDER_OPTIONS {
	char name[16];
	char last_address[128];
	int opengl14;
	int color_correction;
	int shadow_entities;
	int ambient_occlusion;
	float render_distance;
	int window_width;
	int window_height;
	int multisamples;
	int player_arms;
	int fullscreen;
	int bg_tile;
	float bg_tile_speed;
	int ui_accent_r;
	int ui_accent_g;
	int ui_accent_b;
	int lighten_colors;
	int show_names_in_spec;
	int hud_shadows;
	int greedy_meshing;
	int vsync;
	float mouse_sensitivity;
	int show_news;
	int show_fps;
	int volume;
	int voxlap_models;
	int force_displaylist;
	int invert_y;
	int smooth_fog;
	float camera_fov;
	float ads_fov;
	int hold_down_sights;
	float chat_shadow;
	int chat_flip_on_open;
	int chat_spacing;
	float spectator_speed;
	int iron_sight;
	int gmi;
	int disable_raw_input;
	int ui_spacing;
	int ui_padding;
} settings, settings_tmp;

extern struct list config_keys;

struct config_key_pair {
	int internal;
	int def;
	int original;
	int toggle;
	char name[24];
	char display[24];
	char category[24];
};

enum {
	CONFIG_TYPE_STRING,
	CONFIG_TYPE_INT,
	CONFIG_TYPE_FLOAT,
};

struct config_setting {
	void* value;
	int type;
	int min;
	int max;
	char name[32];
	char help[64];
	int defaults[8];
	int defaults_length;
	void (*label_callback)(char* buffer, size_t length, int value, size_t index);
};

extern struct list config_settings;

void config_register_key(int internal, int def, const char* name, int toggle, const char* display,
						 const char* category);
int config_key_translate(int key, int dir, int* results);
struct config_key_pair* config_key(int key);
void config_key_reset_togglestates();
void config_reload(void);
void config_save(void);

#endif
