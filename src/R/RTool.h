/*
 * Copyright (c) 2016 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "RChart.h"
#include "Context.h"

#ifndef _GC_RTool_h

class RGraphicsDevice;
class RTool;
extern RTool *rtool;

class RTool {


    public:
        RTool(int argc, char **argv);
        void  configChanged();

        REmbed *R;
        RGraphicsDevice *dev;

        // the canvas to plot on, it may be null
        // if no canvas is active
        RCanvas *canvas;

        Context *context;
        QString version;

        static SEXP athlete();
        static SEXP athleteHome();
        static SEXP activities();
        static SEXP activity();
        static SEXP metrics();

        bool starting;
        bool failed;

        // handling console output from the R runtime
        static void R_Suicide(const char *) {}
        static void R_ShowMessage(const char *text) { rtool->messages << QString(text); }
        static int R_ReadConsole(const char *, unsigned char *, int, int) { return 0; }
        static void R_WriteConsole(const char *text, int) { rtool->messages << QString(text); }
        static void R_WriteConsoleEx(const char *text, int, int) { rtool->messages << QString(text); }
        static void R_ResetConsole() { }
        static void R_FlushConsole() { }
        static void R_ClearerrConsole() { }

        QStringList messages;
};

// there is a global instance created in main
extern RTool *rtool;

#endif