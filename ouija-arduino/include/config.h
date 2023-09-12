#ifndef __CONFIG_H__
#define __CONFIG_H__

// Various boards
#define LOLIN32_KO  1
#define LOLIN32_ADA 2

// Different comms roles
#define MASTER      1
#define MINION_0    2
#define MINION_1    3

// Change these with each build accordingly
#define BOARD       LOLIN32_ADA
#define COMMS_ROLE  MASTER

#endif