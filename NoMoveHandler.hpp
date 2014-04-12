#ifndef NoMoveHandler_HPP
#define NoMoveHandler_HPP

#define INCL_WINFRAMEMGR
#include <os2.h>           // OS/2
#include <ihandler.hpp>    // IHandler

/* class NoMoveHandler
 *
 * written by St‚phane Charette
 * v1.0  23 November 1998 - initial version
 *
 * PURPOSE:       handle the necessary events to ensure that a window cannot
 *                be moved (cancels out WM_QUERYTRACKINFO and WM_TRACKFRAME)
 *
 * REQUIREMENTS:  IBM VisualAge C++ version 3.0+ for OS/2 Warp version 4.0+
 *                (may also work with Warp 3 -- untested)
 *
 * USAGE:         (see the file NoMoveHandler.cpp)
 *                ...
 *                IFrameWindow frame;
 *                NoMoveHandler handler;
 *                handler.handleEventsFor( &frame );
 *                ...
 *                handler.stopHandlingEventsFor( &frame );
 *                ...
 *
 */
class NoMoveHandler : public IHandler
{
   public:

      // start handling events for the specified window
      virtual IHandler &handleEventsFor( IWindow *window )
      {
         // start the OCL event handling
         IHandler::handleEventsFor( window );

         return *this;
      }

      // stop handling events for the specified window
      virtual IHandler &stopHandlingEventsFor( IWindow *window )
      {
         // stop the OCL event handling
         IHandler::stopHandlingEventsFor( window );

         return *this;
      }

   protected:

      // handle event processing
      virtual Boolean dispatchHandlerEvent( IEvent &event )
      {
         // assume the event wont be handled
         Boolean result = false;

         // look for the WM_VRNENABLED message
         if(  (event.eventId() == WM_QUERYTRACKINFO) ||
              (event.eventId() == WM_TRACKFRAME))
         {
            // prevent this message from being passed to the next handler
            result = true;
         }

         event.setResult(result);
         return result;
      }
};

#endif

