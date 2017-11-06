/*********************************************************************
 * Program name: Rock, Paper, Scissors
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: A game of Rock paper scissors. Similar to playing on
 * the playground except you can set the strength of players. Game
 * is equiped with a AI that makes decision based on player history.
*********************************************************************/

#include "RPSGame.hpp"

int main() {
    // rand() function needs to be seeded only one time. Seeding
    // happens here so that it is only called once.
    unsigned seed;
    seed = time(0);
    srand(seed);

	RPSGame rps;
	rps.playGame();

    return 0;
}
