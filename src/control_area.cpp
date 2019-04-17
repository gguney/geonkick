/**
 * File name: control_area.cpp
 * Project: Geonkick (A kick synthesizer)
 *
 * Copyright (C) 2017 Iurie Nistor (http://geontime.com)
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

#include "oscillator.h"
#include "control_area.h"
#include "oscillator_group_box.h"
#include "general_group_box.h"
#include "effects_group_box.h"
#include "geonkick_api.h"

ControlArea::ControlArea(GeonkickWidget *parent, GeonkickApi* api,
                         const RkSize &size,
                         std::vector<Oscillator*> &oscillators)
                         : GeonkickWidget(parent)
{
        setSize(size);
        int groupBoxWidth = width() / 4 - 5;
        int groupBoxX = 0;
        auto oscillator = oscillators[static_cast<int>(Oscillator::Type::Oscillator1)];
        auto widget = new OscillatorGroupBox(this, oscillator);
        widget->setSize(groupBoxWidth, height());
        widget->setPosition(0, 0);
        RK_ACT_BIND(this, update(), RK_ARGS(), widget, update());
        widget->show();

        oscillator = oscillators[static_cast<int>(Oscillator::Type::Oscillator2)];
        widget = new OscillatorGroupBox(this, oscillator);
        widget->setSize(groupBoxWidth, height());
        widget->setPosition(5 + groupBoxWidth, 0);
        RK_ACT_BIND(this, update(), RK_ARGS(), widget, update());        
        widget->show();
        
        oscillator = oscillators[static_cast<int>(Oscillator::Type::Noise)];
        widget = new OscillatorGroupBox(this, oscillator);
        widget->setSize(groupBoxWidth, height());
        widget->setPosition(2 * (5 + groupBoxWidth), 0);
        RK_ACT_BIND(this, update(), RK_ARGS(), widget, update());
        widget->show();

        auto generalWidget = new GeneralGroupBox(this, api);
        widget->setSize(groupBoxWidth, height());
        widget->setPosition(3 * (5 + groupBoxWidth), 0);
        RK_ACT_BIND(this, update(), RK_ARGS(), generalWidget, update());
        generalWidget->show();

        //        auto effectsWidget = new EffectsGroupBox(api, this);
        //        widget->setSize(groupBoxWidth, height());
        //        widget->setPosition(3 * (5 + groupBoxWidth), 0);
        //        RK_ACT_BIND(this, update(), RK_ARGS(), effectsWidget, update());
        //        effectsWidget->show();
}

ControlArea::~ControlArea()
{

}


