// include the Dark GDK header file (http://forum.thegamecreators.com/?m=forum_read&i=22)
#include "DarkGDK.h"

// main entry point for the application
void DarkGDK ( void )
{
	// PUT YOUR CODE HERE //



	// turn on sync rate and set the maximum rate to 60 fps (frames per second)
	dbSyncOn   ( );
	dbSyncRate ( 60 );

	// stop GDK from responding to the escape key
	// so we can control what happens when escape key is pressed
	dbDisableEscapeKey ( );

	// our main game loop
	while ( LoopGDK ( ) )
	{
		// ADD YOUR LOOP CODE HERE (REPEATING GAME CODE) //


		// break out of the loop when escape key is pressed
		if ( dbEscapeKey ( ) )
			break;

		// update the contents of the screen
		dbSync ( );
	}

	// return back to Windows
	return;
}

//******TEST ALLEN UNDERWOOD**********