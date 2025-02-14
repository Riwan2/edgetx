/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "layout.h"
#include "layout_factory_impl.h"

const uint8_t LBM_LAYOUT_1x2[] = {
#include "mask_layout1x2.lbm"
};

const ZoneOption OPTIONS_LAYOUT_1x2[] =  {
  LAYOUT_COMMON_OPTIONS,
  LAYOUT_OPTIONS_END
};

class Layout1x2: public Layout
{
  public:
    Layout1x2(const LayoutFactory * factory, Layout::PersistentData * persistentData):
      Layout(factory, persistentData)
    {
    }

    unsigned int getZonesCount() const override
    {
      return 2;
    }

    rect_t getZone(unsigned int index) const override
    {
      rect_t zone = getMainZone();

      if (index == 0) {
        return {zone.x, zone.y, zone.w, zone.h / 2};
      }
      else {
        return {zone.x, zone.y + zone.h / 2, zone.w, zone.h / 2};
      }

      return zone;
    }
};

BaseLayoutFactory<Layout1x2> Layout1x2("Layout1x2", "1 x 2", LBM_LAYOUT_1x2, OPTIONS_LAYOUT_1x2);
