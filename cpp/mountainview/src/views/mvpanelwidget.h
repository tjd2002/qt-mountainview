/*
 * Copyright 2016-2017 Flatiron Institute, Simons Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MVPANELWIDGET_H
#define MVPANELWIDGET_H

#include "paintlayer.h"
#include <QWidget>

struct PanelWidgetBehavior {
    bool h_scrollable = true;
    bool v_scrollable = true;

    int minimum_panel_width = 0;
    int minimum_panel_height = 0;

    int preferred_panel_width = 300;
    int preferred_panel_height = 300;

    bool adjust_layout_to_preferred_size = false;
};

class MVPanelWidgetPrivate;
class MVPanelWidget : public QWidget {
    Q_OBJECT
public:
    friend class MVPanelWidgetPrivate;
    MVPanelWidget();
    virtual ~MVPanelWidget();

    void setBehavior(const PanelWidgetBehavior& behavior);

    void clearPanels(bool delete_layers);
    void addPanel(int row, int col, PaintLayer* layer);
    int rowCount() const;
    int columnCount() const;
    void setSpacing(int row_spacing, int col_spacing);
    void setMargins(int row_margin, int col_margin);
    void setZoomOnWheel(bool val);
    int currentPanelIndex() const;
    void setCurrentPanelIndex(int index); //for zooming
    void setViewportGeometry(QRectF geom);

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void paintEvent(QPaintEvent* evt);
    void wheelEvent(QWheelEvent* evt);
    void mousePressEvent(QMouseEvent* evt);
    void mouseReleaseEvent(QMouseEvent* evt);
    void mouseDoubleClickEvent(QMouseEvent* evt);
    void mouseMoveEvent(QMouseEvent* evt);

signals:
    void signalPanelClicked(int index, Qt::KeyboardModifiers modifiers);
    void signalPanelActivated(int index);

private:
    MVPanelWidgetPrivate* d;
};

#endif // MVPANELWIDGET_H
