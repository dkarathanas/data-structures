/************************************************************//**
 * @file   main.c                                      		*
 * @author Nikolaos Batsaras <batsaras@csd.uoc.gr>  		*
 *                                                    		*
 * @brief Main function for the needs of cs-240b project 2017   *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "troy.h"

#define BUFFER_SIZE 1024  /**< Maximum length of a line in input file */

/* Uncomment the following line to enable debugging prints 
 * or comment to disable it */
#define DEBUG

#ifdef DEBUG
#define DPRINT(...) fprintf(stderr, __VA_ARGS__);
#else  /* DEBUG */
#define DPRINT(...)
#endif /* DEBUG */

typedef struct c_soldier c_soldier;
typedef struct general general;
typedef struct TREE_soldier TREE_soldier;
typedef struct soldier soldier;
typedef struct combat combat;

/**
 * @brief Optional function to initialize data structures that 
 * need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize() {
    return 1;
}

/**
 * @brief Register soldier
 *
 * @param sid The soldier's id
 * @param gid The general's id who orders the soldier
 *
 * @return 1 on success
 *         0 on failure
 */
int register_soldier(int sid, int gid) {
    return 1;
}

/**
 * @brief General or King joins the battlefield
 *
 * @param gid The general's id
 *
 * @return 1 on success
 *         0 on failure
 */
int add_general(int gid) {

    TREE_soldier *newnodeTree = (TREE_soldier*) malloc(sizeof(TREE_soldier));
    newnodeTree->sid = -1;
    newnodeTree->p = NULL;
    newnodeTree->rc = NULL;
    newnodeTree->lc = NULL;

    general *newnode = (general*) malloc(sizeof(general));    newnode->gid = gid;
    newnode->combats_no = 0;
    newnode->soldiers_no = 0;
    newnode->soldiers_R = newnodeTree;
    newnode->soldiers_S = newnodeTree;

    if(generals_list == NULL){
        generals_list = newnode;
        newnode->next = NULL;
    }
    else{
        newnode->next = generals_list;
        generals_list = newnode;
    }
    return 1;
}


/**
 * @brief Distribute soldiers to the camps
 * 
 * @return 1 on success
 *         0 on failure
 */
int distribute() {
    return 1;
}

/**
 * @brief General resigns from battlefield
 *
 * @param gid1 The id of general that resigns
 * @param gid2 The id of the general that will  
 * 
 * @return 1 on success
 *         0 on failure
 */
int general_resign(int gid1, int gid2) {
    return 1;
}

/**
 * @brief Prepare for battle
 * 
 * @param gid1 The id of the first general
 * @param gid2 The id of the second general
 * 
 * @return 1 on success
 *         0 on failure
 */
int prepare_battle(int gid1, int gid2) {
    return 1;
}

/**
 * @brief Battle
 * 
 * @param god_favor
 * @param bit_stream A sequence of bits
 * @param bitsno The number of bits in the sequence
 *
 * @return 1 on success
 *         0 on failure
 */
int battle(int god_favor, char *bit_stream, int bitsno) {
    return 1;
}

/**
 * @brief Cease fire
 * 
 * @return 1 on success
 *         0 on failure
 */
int cease_fire() {
    return 1;
}

/**
 * @brief Print general's soldiers
 *
 * @param gid The id of the general
 *
 * @return 1 on success
 *         0 on failure
 */
int print_generals_soldiers(int gid) {
    return 1;
}

/**
 * @brief Print generals
 *
 * @return 1 on success
 *         0 on failure
 */
int print_generals() {
    general *tempGeneral = generals_list;

    printf("\tGENERALS:\n\t");

    while(tempGeneral != NULL){
        printf("%d: ", tempGeneral->gid );
        tempGeneral = tempGeneral->next;
    }

    printf("DONE\n");
    return 1;
}

/**
 * @brief Print registration hashtable
 *
 * @return 1 on success
 *         0 on failure
 */
int print_registration_hashtable() {
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */
int free_world() {
    return 1;
}


/**
 * @brief The main function
 *
 * @param argc Number of arguments
 * @param argv Argument vector
 *
 * @return 0 on success
 *         1 on failure
 */
int main(int argc, char** argv)
{
    FILE *fin = NULL;
    char buff[BUFFER_SIZE], event;

    /* Check command buff arguments */
    if ( argc != 2 ) {
        fprintf(stderr, "Usage: %s <input_file> \n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open input file */
    if (( fin = fopen(argv[1], "r") ) == NULL ) {
        fprintf(stderr, "\n Could not open file: %s\n", argv[1]);
        perror("Opening test file\n");
        return EXIT_FAILURE;
    }

    /* Read input file buff-by-buff and handle the events */
    while ( fgets(buff, BUFFER_SIZE, fin) ) {

        DPRINT("\n>>> Event: %s", buff);

        switch(buff[0]) {

            /* Comment */
            case '#':
            break;

                /* Maximum soldiers */
            case '0':
            {
                sscanf(buff, "%c %d", &event, &max_soldiers_g);
                DPRINT("%c %d\n", event, max_soldiers_g);

                initialize();

                break;
            }

                /* Register soldier
                 * R <sid> <gid> */
            case 'R':
            {
                int sid, gid;

                sscanf(buff, "%c %d %d", &event, &sid, &gid);
                DPRINT("%c %d %d\n", event, sid, gid);

                if ( register_soldier(sid, gid) ) {
                    DPRINT("R %d %d succeeded\n", sid, gid);
                } else {
                    fprintf(stderr, "R %d %d failed\n", sid, gid);
                }

                break;
            }

                /* General or king joins the battlefield
                 * G <gid> */
            case 'G':
            {
                int gid;

                sscanf(buff, "%c %d", &event, &gid);
                DPRINT("%c %d\n", event, gid);

                if ( add_general(gid) ) {
                    DPRINT("%c %d succeeded\n", event, gid);
                } else {
                    fprintf(stderr, "%c %d failed\n", event, gid);
                }

                break;
            }

                /* Distribute soldier
                 * D */
            case 'D':
            {
                sscanf(buff, "%c", &event);
                DPRINT("%c\n", event);

                if ( distribute() ) {
                    DPRINT("%c succeeded\n", event);
                } else {
                    fprintf(stderr, "%c failed\n", event);
                }

                break;
            }

                /* General resigns from battle
                 * M <gid1> <gid2> */
            case 'M':
            {
                int gid1, gid2;

                sscanf(buff, "%c %d %d", &event, &gid1, &gid2);
                DPRINT("%c %d %d\n", event, gid1, gid2);

                if ( general_resign(gid1, gid2) ) {
                    DPRINT("%c %d %d succeeded\n", event, gid1, gid2);
                } else {
                    fprintf(stderr, "%c %d %d failed\n", event, gid1, gid2);
                }

                break;
            }

                /* Prepare for battle
                 * P <gid1> <gid2> */
            case 'P':
            {
                int gid1, gid2;
                sscanf(buff, "%c %d %d", &event, &gid1, &gid2);
                DPRINT("%c %d %d\n", event, gid1, gid2);

                if ( prepare_battle(gid1, gid2) ) {
                    DPRINT("%c %d %d succeeded\n", event, gid1, gid2);
                } else {
                    fprintf(stderr, "%c %d %d failed\n", event, gid1, gid2);
                }

                break;
            }

                /* Battle
                 * B <god_favor> <bit_stream> */
            case 'B':
            {
                int god_favor;
                char bit_stream[9];

                sscanf(buff, "%c %d %s\n", &event, &god_favor, bit_stream);
                DPRINT("%c %d %s\n", event, god_favor, bit_stream);

                if ( battle(god_favor, bit_stream, 8) ) {
                    DPRINT("%c %d %s succeeded\n", event, god_favor, bit_stream);
                } else {
                    fprintf(stderr, "%c %d %s failed\n", event, god_favor, bit_stream);
                }

                break;
            }

                /* Cease fire
                 * U */
            case 'U':
            {
                sscanf(buff, "%c", &event);
                DPRINT("%c\n", event);

                if ( cease_fire() ) {
                    DPRINT("%c succeeded\n", event);
                } else {
                    fprintf(stderr, "%c failed\n", event);
                }

                break;
            }

                /* Print general's soldiers
                 * W <gid> */
            case 'W':
            {
                int gid;

                sscanf(buff, "%c %d", &event, &gid);
                DPRINT("%c %d\n", event, gid);

                if ( print_generals_soldiers(gid) ) {
                    DPRINT("%c %d succeeded\n", event, gid);
                } else {
                    fprintf(stderr, "%c %d failed\n", event, gid);
                }

                break;
            }

                /* Print generals
                 * X */
            case 'X':
            {
                sscanf(buff, "%c", &event);
                DPRINT("%c\n", event);

                if ( print_generals() ) {
                    DPRINT("%c succeeded\n", event);
                } else {
                    fprintf(stderr, "%c failed\n", event);
                }

                break;
            }

                /* Print registration hashtable
                 * Y */
            case 'Y':
            {
                sscanf(buff, "%c", &event);
                DPRINT("%c\n", event);

                if ( print_registration_hashtable() ) {
                    DPRINT("%c succeeded\n", event);
                } else {
                    fprintf(stderr, "%c failed\n", event);
                }

                break;
            }

                /* Empty line */
            case '\n':
            break;

                /* Ignore everything else */
            default:
            DPRINT("Ignoring buff: %s \n", buff);

            break;
        }
    }

    free_world();
    return (EXIT_SUCCESS);
}
