/* This simple application serves as a test for the "no move"
 * window handler.
 *
 * requires IBM VisualAge C++ version 3.0+ for OS/2 Warp v4.0+
 *
 * compile with:  icc.exe /Gm /B"/pm:pm" nomovehandler.cpp
 */

#include <iapp.hpp>     // IApplication
#include <iframe.hpp>   // IFrameWindow

// include the "no move" handler
#include "NoMoveHandler.hpp"

int main()
{
   // create a simple frame window
   IFrameWindow frame("No Move Test");

   // create an instance of the handler
   NoMoveHandler handler;

   // tell the handler to handle events for our window
   handler.handleEventsFor( &frame );

   // show the window -- now just try to move it!
   frame.show().setFocus();

   // run the event processing until the window is closed
   IApplication::current().run();

   // tell our handler to stop event processing
   handler.stopHandlingEventsFor( &frame );

   return 0;
}

