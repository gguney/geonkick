/**
 * File name: file_dialog.h
 * Project: Geonkick (A kick synthesizer)
 *
 * Copyright (C) 2019 Iurie Nistor (http://geontime.com)
 *
 * This file is part of Geonkick.
 *
 * GeonKick is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef GEONKICK_FILE_DIALOG_H
#define GEONKICK_FILE_DIALOG_H

#include "geonkick_widget.h"

class RkLineEdit;
class RkPaintEvent;
class RkMouseEvent;
class GeonkickButton;

class FilesView: public GeonkickWidget {
 public:
        FilesView(GeonkickWidget *parent);
        std::string selectedFile() const;
        RK_DECL_ACT(openFile, openFile(const std::string &fileName),
                    RK_ARG_TYPE(const std::string &), RK_ARG_VAL(fileName));

 protected:
        void createScrollBar();
        void showScrollBar(bool b);
        void paintWidget(const std::shared_ptr<RkPaintEvent> &event) final;
        void mouseButtonPressEvent(const std::shared_ptr<RkMouseEvent> &event) final;
        void mouseDoubleClickEvent(const std::shared_ptr<RkMouseEvent> &event) final;
        void mouseMoveEvent(const std::shared_ptr<RkMouseEvent> &event) final;
        void loadCurrentDirectory();
        int getLine(int x, int y) const;

        void onLineUp();
        void onLineDown();

 private:
        std::vector<std::experimental::filesystem::path> filesList;
        int selectedFileIndex;
        int hightlightLine;
        int offsetIndex;
        std::experimental::filesystem::path currentPath;
        int lineHeight;
        int lineSacing;
        int fisibleLines;
        GeonkickButton *topScrollBarButton;
        GeonkickButton *bottomScrollBarButton;
        int scrollBarWidth;
};

class FileDialog: public GeonkickWidget {
 public:
        enum class Type: int {
                Save,
                Open
        };

        explicit FileDialog(GeonkickWidget *parent, FileDialog::Type type, const std::string& title);
        ~FileDialog() = default;
        RK_DECL_ACT(selectedFile,
                    selectedFile(const std::string &file),
                    RK_ARG_TYPE(const std::string&),
                    RK_ARG_VAL(file));

 protected:
        void onAccept();
        void onCancel();

 private:
        RkLineEdit *fileNameEdit;
        Type dialogType;
        FilesView *filesView;
};

#endif // GEONKICK_FILE_DIALOG_H
