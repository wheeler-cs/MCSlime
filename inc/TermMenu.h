#ifndef _TERMMENU_H
#define _TERMMENU_H

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
 * @brief Print help menu that describes commands to terminal.
 */
void printHelp();

#endif
