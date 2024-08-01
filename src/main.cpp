#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/fmod/fmod.hpp>
#include "popup.hpp"

using namespace geode::prelude;
using namespace keybinds;

// don't judge my code please:) I'm new at coding geode mods
// The main thing is that it works)


$execute{
    /// music

    // 10%
    BindManager::get()->registerBindable({

        "volumeDown"_spr,

        "Decrease volume",

        "Decreases your music volume by 10%",
        
        { Keybind::create(KEY_One, Modifier::Shift) },


        "Music volume control/"
    });

    BindManager::get()->registerBindable({

        "volumeUp"_spr,

        "Increase music volume",

        "Increases your music volume by 10%",

        { Keybind::create(KEY_Two, Modifier::Shift) },


        "Music volume control/"
        });

    // 1%
    BindManager::get()->registerBindable({

        "volumeDownBit"_spr,

        "Decrease music volume",

        "Decreases your music volume by 1%",

        { Keybind::create(KEY_F1, Modifier::Shift)},


        "Music volume control/"
        });

    BindManager::get()->registerBindable({

        "volumeUpBit"_spr,

        "Increase music volume",

        "Increases your music volume by 1%",

        { Keybind::create(KEY_F2, Modifier::Shift) },


        "Music volume control/"
        });

    /// SFX

    // 10%
    BindManager::get()->registerBindable({

        "sfxDown"_spr,

        "Decrease SFX volume",

        "Decrases your SFX volume by 10%",

        { Keybind::create(KEY_One, Modifier::PlatformControl) },


        "SFX volume control/"
        });

    BindManager::get()->registerBindable({

        "sfxUp"_spr,

        "Increase SFX volume",

        "Increases your SFX volume by 10%",

        { Keybind::create(KEY_Two, Modifier::PlatformControl) },


        "SFX volume control/"
        });

    // 1%
    BindManager::get()->registerBindable({

        "sfxDownBit"_spr,

        "Decrease SFX volume",

        "Decreases your SFX volume by 1%",

        { Keybind::create(KEY_F1, Modifier::PlatformControl)},


        "SFX volume control/"
        });

    BindManager::get()->registerBindable({

        "sfxUpBit"_spr,

        "Increase SFX volume",

        "Increases your SFX volume by 1%",

        { Keybind::create(KEY_F2, Modifier::PlatformControl) },


        "SFX volume control/"
        });
}