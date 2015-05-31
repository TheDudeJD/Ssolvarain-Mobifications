/*
 * File:   domains_schools.h
 * Author: Zusuk
 *
 */

#ifndef DOMAINS_SCHOOLS_H
#define	DOMAINS_SCHOOLS_H

#ifdef	__cplusplus
extern "C" {
#endif
/******************************************/

/* if these two values are changed, you have to adjust the respect add_
 functions */
#define MAX_GRANTED_POWERS      5
#define MAX_DOMAIN_SPELLS       9

#define NOSCHOOL           0
#define SCHOOL_NOSCHOOL    0
#define ABJURATION     1
#define CONJURATION    2
#define DIVINATION     3
#define ENCHANTMENT    4
#define EVOCATION      5
#define ILLUSION       6
#define NECROMANCY     7
#define TRANSMUTATION  8
/****************/
#define NUM_SCHOOLS    9

/* domains are in structs.h */

#define DOMAIN_POWER_UNDEFINED                0
  /*air*/
#define DOMAIN_POWER_LIGHTNING_ARC            1
#define DOMAIN_POWER_ELECTRICITY_RESISTANCE   2
  /*earth*/
#define DOMAIN_POWER_ACID_DART                3
#define DOMAIN_POWER_ACID_RESISTANCE          4
  /*fire*/
#define DOMAIN_POWER_FIRE_BOLT                5
#define DOMAIN_POWER_FIRE_RESISTANCE          6
  /*water*/
#define DOMAIN_POWER_ICICLE                   7
#define DOMAIN_POWER_COLD_RESISTANCE          8
  /*chaos*/
#define DOMAIN_POWER_CURSE_TOUCH              9
#define DOMAIN_POWER_CHAOTIC_WEAPON           10
  /*destruction*/
#define DOMAIN_POWER_DESTRUCTIVE_SMITE        11
#define DOMAIN_POWER_DESTRUCTIVE_AURA         12
  /*evil*/
#define DOMAIN_POWER_EVIL_TOUCH               13
#define DOMAIN_POWER_EVIL_SCYTHE              14
  /*good*/
#define DOMAIN_POWER_GOOD_TOUCH               15
#define DOMAIN_POWER_GOOD_LANCE               16
  /*healing*/
#define DOMAIN_POWER_HEALING_TOUCH            17
#define DOMAIN_POWER_EMPOWERED_HEALING        18
  /*knowledge*/
#define DOMAIN_POWER_KNOWLEDGE                19
#define DOMAIN_POWER_EYE_OF_KNOWLEDGE         20
  /*law*/
#define DOMAIN_POWER_BLESSED_TOUCH            21
#define DOMAIN_POWER_LAWFUL_WEAPON            22
  /*trickery*/
#define DOMAIN_POWER_DECEPTION                23
#define DOMAIN_POWER_COPYCAT                  24
#define DOMAIN_POWER_MASS_INVIS               25
  /*protection*/
#define DOMAIN_POWER_RESISTANCE               26
#define DOMAIN_POWER_SAVES                    27
#define DOMAIN_POWER_AURA_OF_PROTECTION       28
  /*travel*/
#define DOMAIN_POWER_ETH_SHIFT                29
  /*war*/
#define DOMAIN_POWER_BATTLE_RAGE              30
#define DOMAIN_POWER_WEAPON_EXPERT            31
  /****************/
#define NUM_DOMAIN_POWERS                     32
/****************/

//extern const char *domain_power_names[NUM_DOMAIN_POWERS + 1];
char *domainpower_names[NUM_DOMAIN_POWERS + 1];
char *school_names[NUM_SCHOOLS + 1];
int restricted_school_reference[NUM_SCHOOLS + 1];

  /****************/
  /****************/

struct domain_info {
  char *name;
  int granted_powers[MAX_GRANTED_POWERS];
  int domain_spells[MAX_DOMAIN_SPELLS];
  ubyte favored_weapon;
  char *description;
};
struct domain_info domain_list[NUM_DOMAINS];

/* haven't started this yet */
struct school_info {
  char *name;
  int ethos;
  int alignment;
  ubyte domains[6];
  ubyte favored_weapon;
  sbyte pantheon;
  char *portfolio;
  char *description;
};
struct school_info school_list[NUM_SCHOOLS];

/******************************************/

void assign_domains(void);
void init_domain_spell_level(void);
void assign_domain_spells(struct char_data *ch);
int has_domain_power(struct char_data *ch, int domain_power);
void clear_domain_feats(struct char_data *ch);
void add_domain_feats(struct char_data *ch);
void perform_destructiveaura(struct char_data *ch);
void disable_restricted_school_spells(struct char_data *ch);


/******************************************/

ACMD(do_domain);

ACMD(do_lightningarc);
ACMD(do_aciddart);
ACMD(do_firebolt);
ACMD(do_icicle);
ACMD(do_cursetouch);
ACMD(do_destructivesmite);
ACMD(do_destructiveaura);
ACMD(do_eviltouch);
ACMD(do_evilscythe);
ACMD(do_goodtouch);
ACMD(do_goodlance);
ACMD(do_healingtouch);
ACMD(do_eyeofknowledge);
ACMD(do_blessedtouch);
ACMD(do_copycat);
ACMD(do_massinvis);
ACMD(do_auraofprotection);
ACMD(do_battlerage);
/* //this is in act.other.c, shared with monks 'outsider' feat
ACMD(do_ethshift);
*/


/******************************************/

#ifdef	__cplusplus
}
#endif

#endif	/* DOMAINS_SCHOOLS_H */

