/**********************************************************************
 * @file   Main.java                                                  *
 * @author Antonis Papaioannou						                  *
 *                                                                    *
 * @brief  Main file for the needs of the Data Structures (HY-240a)   *
 * project (Fall 2017)                                                *
 * Computer Science Department, University of Crete, Greece           *
**********************************************************************/

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    
    /**
	* @brief Optional function to initialize data structures that 
	* need initialization
	*
	* @return true on success
	*         false on failure
	*/
        public static boolean initialize() {
            return true;
        }
        
	/**
	* @brief Register soldier
	*
	* @param sid The soldier's id
        * @param gid The general's id who orders the soldier
	*
	* @return true on success
	*         false on failure
	*/
	public static boolean register(int sid, int gid) {
		return true;
	}
	/**
	 * @brief General or King joins the battlefield
	 *
         * @param gid The general's id
	 * @return true on success
	 *         false on failure
	 */
	public static boolean add_general(int gid) {
		return true;
	}
	/**
	 * @brief Distribute soldiers to the camps
         * 
	 * @return true on success
	 *         false on failure
	 */
	public static boolean distribute() {
		return true;
	}
        
	/**
	 * @brief General resigns from battlefield
	 *
         * @param gid1 The id of general that resigns
         * @param gid2 The id of the general that will  
         * 
	 * @return true on success
	 *         false on failure
	 */
	public static boolean general_resign(int gid1, int gid2) {
		return true;
	}
        
	/**
	 * @brief Prepare for battle
         * 
	 * @param gid1 The id of the first general
         * @param gid2 The id of the second general
         * @param gid3 The id of the third general
         * 
	 * @return true on success
	 *         false on failure
	 */
	public static boolean prepare_battle(int gid1, int gid2, int gid3) {
		return true;
	}
        
	/**
	 * @brief Battle
         * 
         * @param god_favor 
         *
	 * @return true on success
	 *         false on failure
	 */
	public static boolean battle(int god_favor) {
		return true;
	}
        
	/**
	 * @brief Cease fire
         * 
	 * @return true on success
	 *         false on failure
	 */
	public static boolean cease_fire() {
		return true;
	}
        
	/**
	 * @brief Trojan Horse
	 *
	 * @return true on success
	 *         false on failure
	 */
	public static boolean trojan_horse() {
		return true;
	}
        
	/**
	 * @brief Print generals
	 *
	 * @return true on success
	 *         false on failure
	 */
	public static boolean print_generals() {
		return true;
	}
        
	/**
	 * @brief Print registration list
	 *
	 * @return true on success
	 *         false on failure
	 */
	public static boolean print_registration_list() {
		return true;
	}

        
        
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader inputFile;
        String line;
        String [] params;
                
	/* Check command buff arguments */       
        if (args.length != 1) {
            System.err.println("Usage: <executable-name> <input_file>");
            System.exit(0);
        }

	/* Open input file */        
        inputFile = new BufferedReader(new FileReader(args[0]));
		
		initialize();

	/* Read input file and handle the events */
        while ( (line = inputFile.readLine()) != null ) {

            System.out.println(">>> Event: " + line);
            params = line.split(" ");
            char eventID = line.charAt(0);

            switch(eventID) {

		/* Register soldier
		 * R <sid> <gid> */
		case 'R':
		{
                    int sid = Integer.parseInt(params[1]);
                    int gid = Integer.parseInt(params[2]);

                    if (register(sid, gid)) {
                        System.out.println("R " + sid + " " + gid + " succeeded");
                    } else {
                        System.err.println("R " + sid + " " + gid + " failed");
                    }
                    break;
		}

		/* General or king joins the battlefield
		 * G <gid> */
		case 'G':
		{
                    int gid = Integer.parseInt(params[1]);
                    
                    if (add_general(gid)) {
                        System.out.println("G " + gid + " succeeded");
                    } else {
                        System.err.println("G " + gid + " failed");
                    }
                    break;
		}

		/* Distribute soldiers
		 * D */
		case 'D':
		{   
                    if (distribute()) {
                        System.out.println("D " + " succeeded");
                    } else {
                        System.err.println("D " + " failed");
                    }
                    break;
		}

		/* General resigns from battle
		 * M <gid1> <gid2> */
		case 'M':
		{
                    int gid1 = Integer.parseInt(params[1]);
                    int gid2 = Integer.parseInt(params[2]);
                    
                    if (general_resign(gid1, gid2)) {
                        System.out.println("M " + gid1 + " " + gid2 + " succeeded");
                    } else {
                        System.err.println("M " + gid1 + " " + gid2 + " failed");
                    }
                    break;
		}

		/* Prepare for battle
		 * P <gid1> <gid2> <gid3> */
		case 'P':
		{
                    int gid1 = Integer.parseInt(params[1]);
                    int gid2 = Integer.parseInt(params[2]);
                    int gid3 = Integer.parseInt(params[3]);
                    
                    if (prepare_battle(gid1, gid2, gid3)) {
                        System.out.println("P " + gid1 + " " + gid2 + " " + gid3 + " succeeded");
                    } else {
                        System.err.println("P " + gid1 + " " + gid2 + " " + gid3 + " failed");
                    }
                    break;
		}

		/* Battle
		 * B <god_favor> */
		case 'B':
		{
                    int god_favor = Integer.parseInt(params[1]);
                    
                    if (battle(god_favor)) {
                        System.out.println("B " + god_favor + " succeeded");
                    } else {
                        System.err.println("B " + god_favor + " failed");
                    }
                    break;
		}

		/* Cease fire
		 * U */
		case 'U':
		{
                    if (cease_fire()) {
                        System.out.println("U " + " succeeded");
                    } else {
                        System.err.println("U " + " failed");
                    }
                    break;
		}

		/* Trojan Horse
		 * T */
		case 'T':
		{                    
                    if (trojan_horse()) {
                        System.out.println("T succeeded");
                    } else {
                        System.err.println("T failed");
                    }
                    break;
		}
                
                /* Print generals
                 * X */
                case 'X':
                {
                    if (print_generals()) {
                        System.out.println("X succeeded");
                    } else {
                        System.err.println("X failed");
                    }
                    break;
                    
                }
                
        /* Print registration list
		 * Y */
		case 'Y':
		{
			 if (print_registration_list()) {
					System.out.println("Y succeeded");
              } else {
                  	System.err.println("Y failed");
             }
             break;
		}

		/* Empty line */
		case '\n':
			break;

		/* Ignore everything else */
		default:
                    System.out.println("Ignoring " + line);
                    break;
		}
	}

    }
           
}
