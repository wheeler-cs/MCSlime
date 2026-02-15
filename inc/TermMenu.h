#ifndef _TERMMENU_H
#define _TERMMENU_H

#define COMMAND_BUFFER_SIZE 8

/**
 * @brief Run the main menu of the interactive terminal session.
 */
void mainMenu();

/**
 * @brief Parse command entered into terminal.
 * 
 * @param buffer Text from I/O buffer to be parsed.
 * @param parsedCommand Parsed command.
 * @param componentQuant Number of components parsed from buffer.
 */
void parseCommand(char *, char [][256], unsigned int *);

/**
 * @brief Calls map generation function if arguments are appropriate.
 * 
 * @param components Parsed components of a command entered in terminal.
 * @param componentQuant Number of components in `components` array.
 */
void tryGenerateMap(char [][256], unsigned int);

/**
 * @brief Print help menu that describes commands to terminal.
 */
void printHelp();

/**
 * @brief Print a progress bar to the terminal.
 * 
 * @param x Cursor position along terminal columns to start progress bar from.
 * @param y Cursor position along terminal rows to start progress bar from.
 * @param width Width of progress bar in columns to be printed.
 * @param progress Percentage of progress bar completed.
 */
void printProgressBar(unsigned int, unsigned int, unsigned int, double);

#endif
