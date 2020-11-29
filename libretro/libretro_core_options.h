#ifndef LIBRETRO_CORE_OPTIONS_H__
#define LIBRETRO_CORE_OPTIONS_H__

#include <stdlib.h>
#include <string.h>

#include <libretro.h>
#include <retro_inline.h>

#ifndef HAVE_NO_LANGEXTRA
#include "libretro_core_options_intl.h"
#endif

/*
 ********************************
 * VERSION: 1.3
 ********************************
 *
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_ENGLISH */

/* Default language:
 * - All other languages must include the same keys and values
 * - Will be used as a fallback in the event that frontend language
 *   is not available
 * - Will be used as a fallback for any missing entries in
 *   frontend language definition */

struct retro_core_option_definition option_defs_us[] = {
   {
      "nestopia_blargg_ntsc_filter",
      "Blargg NTSC滤镜",
      "启用Blargg NTSC滤镜. ",
      {
         { "disabled",   NULL },
         { "composite",  "复合视频" },
         { "svideo",     "S-Video" },
         { "rgb",        "RGB SCART" },
         { "monochrome", "黑白" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "nestopia_palette",
      "调色板",
      "选择要使用的调色板. ",
      {
         { "cxa2025as",            "CXA2025AS" },
         { "consumer",             "Consumer" },
         { "canonical",            "Canonical" },
         { "alternative",          "Alternative" },
         { "rgb",                  "RGB" },
         { "pal",                  "PAL" },
         { "composite-direct-fbx", "Composite Direct FBx" },
         { "pvm-style-d93-fbx",    "PVM-style D93 FBx" },
         { "ntsc-hardware-fbx",    "NTSC hardware FBx" },
         { "nes-classic-fbx-fs",   "NES Classic FBx FS" },
         { "raw",                  "Raw" },
         { "custom",               "Custom" },
         { NULL, NULL },
      },
      "cxa2025as" /* TODO/FIXME - is this correct ? */
   },
   {
      "nestopia_nospritelimit",
      "移除活动块限制",
      "移除每扫描线8个活动块的硬件限制. ",
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "nestopia_overclock",
      "CPU速度 (超频) ",
      "对模拟的CPU进行超频. ",
      {
         { "1x", NULL },
         { "2x", NULL },
         { NULL, NULL },
      },
      "1x"
   },
   {
      "nestopia_select_adapter",
      "4打适配器",
      "手动选择4打适配器. \n"
	  "有些游戏无法通过NstDatabase.xml数据库正确识别适配器, 此项可以帮助解决此问题. ",
      {
         { "auto",    "自动" },
         { "ntsc",    "NTSC" },
         { "famicom", "Famicom" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "nestopia_fds_auto_insert",
      "磁盘自动插入",
      "复位时自动插入第一张磁盘. ",
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "nestopia_overscan_v",
      "剪切过扫描 (垂直) ",
      "剪切垂直方向的应该被标准电视的边框隐藏的过扫描区域. ",
      {
         { "enabled",  "启用" },
         { "disabled", "禁用" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "nestopia_overscan_h",
      "剪切过扫描 (水平) ",
      "剪切水平方向的应该被标准电视的边框隐藏的过扫描区域. ",
      {
         { "enabled",  "启用" },
         { "disabled", "禁用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "nestopia_aspect",
      "输出宽高比",
      "选择输出宽高比. RetroArch的宽高比必须设为'内核提供'. \n"
	  "'自动'会使用NstDatabase.xml数据库文件自动检测宽高比. \n"
	  "如果没有数据库文件, '自动'缺省为NTSC. ",
      {
         { "auto", "自动" },
         { "ntsc", "NTSC" },
         { "pal",  "PAL" },
         { "4:3",  "4:3" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "nestopia_genie_distortion",
      "金手指卡声音变形",
      "金手指设备会不经意的导致声音变形. \n"
	  "启用此项可以模拟这种变形, 添加到游戏声音中去. ",
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "nestopia_favored_system",
      "系统区域",
      "选择系统区域. \n"
	  "'自动'会使用NstDatabase.xml数据库自动检测区域. \n"
	  "如果没有数据库文件, '自动'缺省为NTSC. ",
      {
         { "auto",    "自动" },
         { "ntsc",    "NTSC" },
         { "pal",     "PAL" },
         { "famicom", "Famicom" },
         { "dendy",   "Dendy" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "nestopia_ram_power_state",
      "内存启动状态",
      "",
      {
         { "0x00",   NULL },
         { "0xFF",   NULL },
         { "random", "随机" },
         { NULL, NULL },
      },
      "0x00"
   },
   {
      "nestopia_button_shift",
      "顺时针移动按键",
      "顺时针旋转A/B/X/Y按键. ", /* is this right? @gadsby */
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "nestopia_turbo_pulse",
      "连发键速度",
      "设置连发键A和B的连发速度. ",
      {
         { "2", NULL },
         { "3", NULL },
         { "4", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { "8", NULL },
         { "9", NULL },
         { NULL, NULL },
      },
      "2"
   },
   {
      "nestopia_audio_vol_sq1",
      "矩形波声道1音量 %",
      "修改矩形波声道1音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_sq2",
      "矩形波声道2音量 %",
      "修改矩形波声道2音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_tri",
      "三角波声道音量 %",
      "修改三角波声道音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_noise",
      "噪音声道音量 %",
      "修改噪音声道音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_dpcm",
      "DPCM声道音量 %",
      "修改DPCM声道音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_fds",
      "FDS声道音量 %",
      "修改FDS声道音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_mmc5",
      "MMC5声道音量 %",
      "修改MMC5声道音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_vrc6",
      "VRC6声道音量 %",
      "修改VRC6声道音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_vrc7",
      "VRC7声道音量 %",
      "修改VRC7声道音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_n163",
      "N163声道音量 %",
      "修改N163声道音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "nestopia_audio_vol_s5B",
      "S5B声道音量 %",
      "修改S5B声道音量  %.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   { NULL, NULL, NULL, {{0}}, NULL },
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

#ifndef HAVE_NO_LANGEXTRA
struct retro_core_option_definition *option_defs_intl[RETRO_LANGUAGE_LAST] = {
   option_defs_us, /* RETRO_LANGUAGE_ENGLISH */
   NULL,           /* RETRO_LANGUAGE_JAPANESE */
   NULL,           /* RETRO_LANGUAGE_FRENCH */
   NULL,           /* RETRO_LANGUAGE_SPANISH */
   NULL,           /* RETRO_LANGUAGE_GERMAN */
   NULL,           /* RETRO_LANGUAGE_ITALIAN */
   NULL,           /* RETRO_LANGUAGE_DUTCH */
   NULL,           /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   NULL,           /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   NULL,           /* RETRO_LANGUAGE_RUSSIAN */
   NULL,           /* RETRO_LANGUAGE_KOREAN */
   NULL,           /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   NULL,           /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   NULL,           /* RETRO_LANGUAGE_ESPERANTO */
   NULL,           /* RETRO_LANGUAGE_POLISH */
   NULL,           /* RETRO_LANGUAGE_VIETNAMESE */
   NULL,           /* RETRO_LANGUAGE_ARABIC */
   NULL,           /* RETRO_LANGUAGE_GREEK */
   option_defs_tr, /* RETRO_LANGUAGE_TURKISH */
};
#endif

/*
 ********************************
 * Functions
 ********************************
*/

/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

static INLINE void libretro_set_core_options(retro_environment_t environ_cb)
{
   unsigned version = 0;

   if (!environ_cb)
      return;

   if (environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version) && (version >= 1))
   {
#ifndef HAVE_NO_LANGEXTRA
      struct retro_core_options_intl core_options_intl;
      unsigned language = 0;

      core_options_intl.us    = option_defs_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
          (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = option_defs_intl[language];

      environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_intl);
#else
      environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS, &option_defs_us);
#endif
   }
   else
   {
      size_t i;
      size_t num_options               = 0;
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      /* Allocate arrays */
      variables  = (struct retro_variable *)calloc(num_options + 1, sizeof(struct retro_variable));
      values_buf = (char **)calloc(num_options, sizeof(char *));

      if (!variables || !values_buf)
         goto error;

      /* Copy parameters from option_defs_us array */
      for (i = 0; i < num_options; i++)
      {
         const char *key                        = option_defs_us[i].key;
         const char *desc                       = option_defs_us[i].desc;
         const char *default_value              = option_defs_us[i].default_value;
         struct retro_core_option_value *values = option_defs_us[i].values;
         size_t buf_len                         = 3;
         size_t default_index                   = 0;

         values_buf[i] = NULL;

         if (desc)
         {
            size_t num_values = 0;

            /* Determine number of values */
            while (true)
            {
               if (values[num_values].value)
               {
                  /* Check if this is the default value */
                  if (default_value)
                     if (strcmp(values[num_values].value, default_value) == 0)
                        default_index = num_values;

                  buf_len += strlen(values[num_values].value);
                  num_values++;
               }
               else
                  break;
            }

            /* Build values string */
            if (num_values > 0)
            {
               size_t j;

               buf_len += num_values - 1;
               buf_len += strlen(desc);

               values_buf[i] = (char *)calloc(buf_len, sizeof(char));
               if (!values_buf[i])
                  goto error;

               strcpy(values_buf[i], desc);
               strcat(values_buf[i], "; ");

               /* Default value goes first */
               strcat(values_buf[i], values[default_index].value);

               /* Add remaining values */
               for (j = 0; j < num_values; j++)
               {
                  if (j != default_index)
                  {
                     strcat(values_buf[i], "|");
                     strcat(values_buf[i], values[j].value);
                  }
               }
            }
         }

         variables[i].key   = key;
         variables[i].value = values_buf[i];
      }

      /* Set variables */
      environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);

error:

      /* Clean up */
      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}

#ifdef __cplusplus
}
#endif

#endif
