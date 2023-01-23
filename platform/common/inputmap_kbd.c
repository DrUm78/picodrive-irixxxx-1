#include <stdlib.h>
#include <SDL_keysym.h>

#include "../libpicofe/input.h"
#include "../libpicofe/in_sdl.h"
#include "../common/input_pico.h"
#include "../common/plat_sdl.h"

/*const struct in_default_bind in_sdl_defbinds[] = {
	{ SDLK_UP,     IN_BINDTYPE_PLAYER12, GBTN_UP },
	{ SDLK_DOWN,   IN_BINDTYPE_PLAYER12, GBTN_DOWN },
	{ SDLK_LEFT,   IN_BINDTYPE_PLAYER12, GBTN_LEFT },
	{ SDLK_RIGHT,  IN_BINDTYPE_PLAYER12, GBTN_RIGHT },
	{ SDLK_z,      IN_BINDTYPE_PLAYER12, GBTN_A },
	{ SDLK_x,      IN_BINDTYPE_PLAYER12, GBTN_B },
	{ SDLK_c,      IN_BINDTYPE_PLAYER12, GBTN_C },
	{ SDLK_a,      IN_BINDTYPE_PLAYER12, GBTN_X },
	{ SDLK_s,      IN_BINDTYPE_PLAYER12, GBTN_Y },
	{ SDLK_d,      IN_BINDTYPE_PLAYER12, GBTN_Z },
	{ SDLK_RETURN, IN_BINDTYPE_PLAYER12, GBTN_START },
	{ SDLK_f,      IN_BINDTYPE_PLAYER12, GBTN_MODE },
	{ SDLK_ESCAPE, IN_BINDTYPE_EMU, PEVB_MENU },
	{ SDLK_TAB,    IN_BINDTYPE_EMU, PEVB_RESET },
	{ SDLK_F1,     IN_BINDTYPE_EMU, PEVB_STATE_SAVE },
	{ SDLK_F2,     IN_BINDTYPE_EMU, PEVB_STATE_LOAD },
	{ SDLK_F3,     IN_BINDTYPE_EMU, PEVB_SSLOT_PREV },
	{ SDLK_F4,     IN_BINDTYPE_EMU, PEVB_SSLOT_NEXT },
	{ SDLK_F5,     IN_BINDTYPE_EMU, PEVB_SWITCH_RND },
	{ SDLK_F6,     IN_BINDTYPE_EMU, PEVB_PICO_PPREV },
	{ SDLK_F7,     IN_BINDTYPE_EMU, PEVB_PICO_PNEXT },
	{ SDLK_F8,     IN_BINDTYPE_EMU, PEVB_PICO_SWINP },
	{ SDLK_BACKSPACE, IN_BINDTYPE_EMU, PEVB_FF },
	{ 0, 0, 0 }
};*/

const struct in_default_bind in_sdl_defbinds[] = {
	{ SDLK_u,     	IN_BINDTYPE_PLAYER12, GBTN_UP },
	{ SDLK_d,		IN_BINDTYPE_PLAYER12, GBTN_DOWN },
	{ SDLK_l,   	IN_BINDTYPE_PLAYER12, GBTN_LEFT },
	{ SDLK_r,  		IN_BINDTYPE_PLAYER12, GBTN_RIGHT },
	{ SDLK_y,       IN_BINDTYPE_PLAYER12, GBTN_A },
	{ SDLK_b,      	IN_BINDTYPE_PLAYER12, GBTN_B },
	{ SDLK_a,      	IN_BINDTYPE_PLAYER12, GBTN_C },
	{ SDLK_m,       IN_BINDTYPE_PLAYER12, GBTN_X },
	{ SDLK_x,      	IN_BINDTYPE_PLAYER12, GBTN_Y },
	{ SDLK_n,      	IN_BINDTYPE_PLAYER12, GBTN_Z },
	{ SDLK_s, 		IN_BINDTYPE_PLAYER12, GBTN_START },
	{ SDLK_k,      	IN_BINDTYPE_PLAYER12, GBTN_MODE },
	{ SDLK_q, 		IN_BINDTYPE_EMU, PEVB_MENU },
	{ SDLK_TAB,    	IN_BINDTYPE_EMU, PEVB_RESET },
	//{ SDLK_p,     	IN_BINDTYPE_EMU, PEVB_STATE_SAVE },
	{ SDLK_F1,      IN_BINDTYPE_EMU, PEVB_STATE_SAVE },
	{ SDLK_F2,     	IN_BINDTYPE_EMU, PEVB_STATE_LOAD },

	{ SDLK_e,     	IN_BINDTYPE_EMU, PEVB_VOL_DOWN },
	{ SDLK_c,     	IN_BINDTYPE_EMU, PEVB_VOL_UP },
	{ SDLK_w,     	IN_BINDTYPE_EMU, PEVB_BRIGHT_DOWN },
	{ SDLK_g,     	IN_BINDTYPE_EMU, PEVB_BRIGHT_UP },
	{ SDLK_j,     	IN_BINDTYPE_EMU, PEVB_AR_FACT_DOWN },
	{ SDLK_i,     	IN_BINDTYPE_EMU, PEVB_AR_FACT_UP },
	{ SDLK_h,     	IN_BINDTYPE_EMU, PEVB_DISPMODE },

	{ SDLK_F3,     	IN_BINDTYPE_EMU, PEVB_SSLOT_PREV },
	{ SDLK_F4,     	IN_BINDTYPE_EMU, PEVB_SSLOT_NEXT },
	{ SDLK_F5,     	IN_BINDTYPE_EMU, PEVB_SWITCH_RND },
	{ SDLK_F6,     	IN_BINDTYPE_EMU, PEVB_PICO_PPREV },
	{ SDLK_F7,     	IN_BINDTYPE_EMU, PEVB_PICO_PNEXT },
	{ SDLK_F8,     	IN_BINDTYPE_EMU, PEVB_PICO_SWINP },
	{ SDLK_BACKSPACE, IN_BINDTYPE_EMU, PEVB_FF },
	{ 0, 0, 0 }
};

const struct in_default_bind in_sdl_defbinds_SMS[] = {
	{ SDLK_u,       IN_BINDTYPE_PLAYER12, GBTN_UP },
	{ SDLK_d,       IN_BINDTYPE_PLAYER12, GBTN_DOWN },
	{ SDLK_l,       IN_BINDTYPE_PLAYER12, GBTN_LEFT },
	{ SDLK_r,       IN_BINDTYPE_PLAYER12, GBTN_RIGHT },
	{ SDLK_y,       IN_BINDTYPE_PLAYER12, GBTN_C },
	{ SDLK_a,       IN_BINDTYPE_PLAYER12, GBTN_C },
	{ SDLK_b,       IN_BINDTYPE_PLAYER12, GBTN_B },
	{ SDLK_x,       IN_BINDTYPE_PLAYER12, GBTN_B },
	{ SDLK_m,       IN_BINDTYPE_PLAYER12, GBTN_X },
	{ SDLK_n,       IN_BINDTYPE_PLAYER12, GBTN_Z },
	{ SDLK_s,       IN_BINDTYPE_PLAYER12, GBTN_START },
	{ SDLK_k,       IN_BINDTYPE_PLAYER12, GBTN_MODE },
	{ SDLK_q,       IN_BINDTYPE_EMU, PEVB_MENU },
	{ SDLK_TAB,     IN_BINDTYPE_EMU, PEVB_RESET },
	//{ SDLK_p,       IN_BINDTYPE_EMU, PEVB_STATE_SAVE },
	{ SDLK_F1,      IN_BINDTYPE_EMU, PEVB_STATE_SAVE },
	{ SDLK_F2,      IN_BINDTYPE_EMU, PEVB_STATE_LOAD },

	{ SDLK_e,       IN_BINDTYPE_EMU, PEVB_VOL_DOWN },
	{ SDLK_c,       IN_BINDTYPE_EMU, PEVB_VOL_UP },
	{ SDLK_w,       IN_BINDTYPE_EMU, PEVB_BRIGHT_DOWN },
	{ SDLK_g,       IN_BINDTYPE_EMU, PEVB_BRIGHT_UP },
	{ SDLK_j,       IN_BINDTYPE_EMU, PEVB_AR_FACT_DOWN },
	{ SDLK_i,       IN_BINDTYPE_EMU, PEVB_AR_FACT_UP },
	{ SDLK_h,       IN_BINDTYPE_EMU, PEVB_DISPMODE },

	{ SDLK_F3,      IN_BINDTYPE_EMU, PEVB_SSLOT_PREV },
	{ SDLK_F4,      IN_BINDTYPE_EMU, PEVB_SSLOT_NEXT },
	{ SDLK_F5,      IN_BINDTYPE_EMU, PEVB_SWITCH_RND },
	{ SDLK_F6,      IN_BINDTYPE_EMU, PEVB_PICO_PPREV },
	{ SDLK_F7,      IN_BINDTYPE_EMU, PEVB_PICO_PNEXT },
	{ SDLK_F8,      IN_BINDTYPE_EMU, PEVB_PICO_SWINP },
	{ SDLK_BACKSPACE, IN_BINDTYPE_EMU, PEVB_FF },
	{ 0, 0, 0 }
};

const struct menu_keymap in_sdl_key_map[] = {
	{ SDLK_u,	PBTN_UP },
	{ SDLK_d,	PBTN_DOWN },
	{ SDLK_l,	PBTN_LEFT },
	{ SDLK_r,	PBTN_RIGHT },
	{ SDLK_a,	PBTN_MOK },
	{ SDLK_b,	PBTN_MBACK },
	{ SDLK_SEMICOLON,	PBTN_MA2 },
	{ SDLK_QUOTE,	PBTN_MA3 },
	{ SDLK_m,  PBTN_L },
	{ SDLK_n, PBTN_R },
};
const int in_sdl_key_map_sz = sizeof(in_sdl_key_map) / sizeof(in_sdl_key_map[0]);

const struct menu_keymap in_sdl_joy_map[] = {
	{ SDLK_UP,	PBTN_UP },
	{ SDLK_DOWN,	PBTN_DOWN },
	{ SDLK_LEFT,	PBTN_LEFT },
	{ SDLK_RIGHT,	PBTN_RIGHT },
	/* joystick */
	{ SDLK_WORLD_0,	PBTN_MOK },
	{ SDLK_WORLD_1,	PBTN_MBACK },
	{ SDLK_WORLD_2,	PBTN_MA2 },
	{ SDLK_WORLD_3,	PBTN_MA3 },
};
const int in_sdl_joy_map_sz = sizeof(in_sdl_joy_map) / sizeof(in_sdl_joy_map[0]);

const char * const (*in_sdl_key_names)[SDLK_LAST] = NULL;
