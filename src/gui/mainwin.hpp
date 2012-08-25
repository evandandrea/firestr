/*
 * Copyright (C) 2012  Maxim Noah Khailo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FIRESTR_MAINWIN_H
#define FIRESTR_MAINWIN_H

#include <QMainWindow>

#include "gui/messagelist.hpp"
#include "message/postoffice.hpp"

namespace fire
{
    namespace gui
    {
        class main_window : public QMainWindow
        {
            Q_OBJECT
            public:
                main_window(
                        const std::string& host, 
                        const std::string& port);

            private slots:
                void about();
                void test();

            private:
                void setup_post(
                        const std::string& host, 
                        const std::string& port);
                void create_actions();
                void create_main();
                void create_menus();

            private:
                QMenu *_main_menu;
                QAction *_close_action;
                QAction *_about_action;
                QAction *_test_action;

                QWidget* _root;
                QVBoxLayout* _layout;

                message_list* _messages;
                fire::message::post_office_ptr _master;
        };
    }
}

#endif