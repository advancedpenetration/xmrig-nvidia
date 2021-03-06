/* XMRig
 * Copyright 2014      imonero <https://github.com/global-blockchain>
 * Copyright 2016-2017 XMRig       <admin@imonero.org>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef XMRIG_CONTROLLER_H
#define XMRIG_CONTROLLER_H


#include "common/interfaces/IWatcherListener.h"


class Network;
class StatsData;


namespace xmrig {


class Config;
class ControllerPrivate;
class IControllerListener;


class Controller : public IWatcherListener
{
public:
    Controller();
    ~Controller() override;

    bool isReady() const;
    Config *config() const;
    int init(int argc, char **argv);
    Network *network() const;
    void addListener(IControllerListener *listener);

protected:
    void onNewConfig(IConfig *config) override;

private:
    ControllerPrivate *d_ptr;
};

} /* namespace xmrig */

#endif /* XMRIG_CONTROLLER_H */
