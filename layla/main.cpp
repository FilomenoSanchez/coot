/* layla/main.cpp
 * 
 * Copyright 2023 by Global Phasing Ltd.
 * Author: Jakub Smulski
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */

#include "Python.h"
#include <gtk/gtk.h>
#include <thread>
#include "utils/coot-utils.hh"
#include "ligand_builder_state.hpp"
#include "ligand_builder_generators.hpp"
#include "ligand_builder_ui.hpp"
#include "python-utils.hpp"


// #include "../src/coot-setup-python.hh"

int main(int argc, char** argv) {
    using namespace coot::ligand_editor;

    std::thread python_init_thread([argc,argv](){
        layla_setup_python_basic(argc, argv);
        // layla_setup_python_module("coot");
        // layla_setup_python_module("coot_utils");
    });

    python_init_thread.detach();

    gtk_init();

    GtkApplication* app = gtk_application_new("org.pemsley.Layla", G_APPLICATION_DEFAULT_FLAGS);
    GError *error = NULL;
    g_application_register(G_APPLICATION(app), NULL, &error);

    g_signal_connect(app, "activate", G_CALLBACK(+[](GtkApplication* app, gpointer user_data) {

        std::string dir = coot::package_data_dir();
        // all ui files should live here:
        std::string dir_ui = coot::util::append_dir_dir(dir, "ui");
        std::string ui_file_name = "layla.ui";
        std::string ui_file_full = coot::util::append_dir_file(dir_ui, ui_file_name);
        // allow local override
        if (coot::file_exists(ui_file_name)) ui_file_full = ui_file_name;
        GError* error = NULL;
        GtkBuilder* builder = gtk_builder_new();
        gboolean status = gtk_builder_add_from_file(builder, ui_file_full.c_str(), &error);
        if (status == FALSE) {
            std::cout << "ERROR:: Failure to read or parse " << ui_file_full << std::endl;
            std::cout << error->message << std::endl;
            exit(0);
        }

        auto *win = coot::ligand_editor::setup_main_window(app, builder);

        // for now
        auto* icon_theme = gtk_icon_theme_get_for_display(gtk_widget_get_display(GTK_WIDGET(win)));
        std::string full_path_for_icons = coot::util::append_dir_dir(dir, "icons");
        gtk_icon_theme_add_search_path(icon_theme, full_path_for_icons.c_str());

        coot::ligand_editor::global_layla_gtk_builder = builder;
        coot::ligand_editor::global_generator_request_task_cancellable = nullptr;

        gtk_window_present(GTK_WINDOW(win));
        gtk_application_add_window(app,GTK_WINDOW(win));
    }), NULL);

    auto ret = g_application_run(G_APPLICATION(app),0,0);
    g_info("Exiting...");
    delete coot::ligand_editor::global_instance;
    return ret;
}