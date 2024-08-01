#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/fmod/fmod.hpp>
#include "popup.hpp"
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/MenuLayer.hpp>   

using namespace geode::prelude;
using namespace keybinds;


VolumePopup* popupLayer;
bool firstLoad = false;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        if (firstLoad == false) {
            popupLayer = VolumePopup::create(CCScene::get());
            SceneManager::get()->keepAcrossScenes(popupLayer);
            firstLoad = true;
        }


        return true;
    }
};

void VolumePopup::labelUpdate() {
    int musicVolumeGet = FMODAudioEngine::get()->getBackgroundMusicVolume() * 100;
    std::string musicVolumeShow = "Music: " + std::to_string(musicVolumeGet) + "%";
    int SFXVolumeGet = FMODAudioEngine::get()->getEffectsVolume() * 100;
    std::string SFXVolumeShow = "SFX: " + std::to_string(SFXVolumeGet) + "%";
    musicVolumeLabel->setString((musicVolumeShow).c_str(), true);
    SFXVolumeLabel->setString((SFXVolumeShow).c_str(), true);
}

void VolumePopup::pushPopup() {
	float duration = Mod::get()->getSettingValue<double>("dissapear-time");

	bg->runAction(CCSequence::create(
		CCEaseOut::create(CCMoveBy::create(0.5f, { -135.f, 0.0f }), 0.6f),
		CCDelayTime::create(duration),
		CCEaseIn::create(CCMoveBy::create(0.5f, { 135.f, 0.0f }), 0.6f),
		CCDelayTime::create(0.5F),
		nullptr

	));
	musicVolumeLabel->runAction(CCSequence::create(
		CCEaseOut::create(CCMoveBy::create(0.5f, { -135.f, 0.0f }), 0.6f),
		CCDelayTime::create(duration),
		CCEaseIn::create(CCMoveBy::create(0.5f, { 135.f, 0.0f }), 0.6f),
		CCDelayTime::create(0.5F),
		nullptr

	));
	SFXVolumeLabel->runAction(CCSequence::create(
		CCEaseOut::create(CCMoveBy::create(0.5f, { -135.f, 0.0f }), 0.6f),
		CCDelayTime::create(duration),
		CCEaseIn::create(CCMoveBy::create(0.5f, { 135.f, 0.0f }), 0.6f),
		CCDelayTime::create(0.5F),
		nullptr

	));
}

void VolumePopup::popupExtendTime() {
	float duration = Mod::get()->getSettingValue<double>("dissapear-time");

	if (bg->getPositionX() == 505.f) {
		bg->stopAllActions();
		musicVolumeLabel->stopAllActions();
		SFXVolumeLabel->stopAllActions();
		bg->runAction(CCSequence::create(
			CCDelayTime::create(duration),
			CCEaseIn::create(CCMoveBy::create(0.5f, { 135.f, 0.0f }), 0.6f),
			CCDelayTime::create(0.5F),
			nullptr

		));
		musicVolumeLabel->runAction(CCSequence::create(
			CCDelayTime::create(duration),
			CCEaseIn::create(CCMoveBy::create(0.5f, { 135.f, 0.0f }), 0.6f),
			CCDelayTime::create(0.5F),
			nullptr

		));
		SFXVolumeLabel->runAction(CCSequence::create(
			CCDelayTime::create(duration),
			CCEaseIn::create(CCMoveBy::create(0.5f, { 135.f, 0.0f }), 0.6f),
			CCDelayTime::create(0.5F),
			nullptr

		));
	}
}

void VolumePopup::volumeLimit() {
	if (FMODAudioEngine::get()->getBackgroundMusicVolume() < 0.000000) {
		FMODAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.f);
	}
	if (FMODAudioEngine::get()->getBackgroundMusicVolume() > 1.000000) {
		FMODAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.f);
	}
	if (FMODAudioEngine::get()->getEffectsVolume() < 0.000000) {
		FMODAudioEngine::sharedEngine()->setEffectsVolume(0.f);
	}
	if (FMODAudioEngine::get()->getEffectsVolume() > 1.000000) {
		FMODAudioEngine::sharedEngine()->setEffectsVolume(1.f);
	}
}

void VolumePopup::volumeChange(float value, std::string value2) {
	if (bg->getPositionX() == 640.f) pushPopup();
	if (value2 == "music") {
		float musicVolume = FMODAudioEngine::get()->getBackgroundMusicVolume();
		FMODAudioEngine::sharedEngine()->setBackgroundMusicVolume(musicVolume + value);
		volumeLimit();

		if (bg->getPositionX() == 505.f) popupExtendTime();
	}
	else if (value2 == "sfx") {
		float SFXVolume = FMODAudioEngine::get()->getEffectsVolume();
		FMODAudioEngine::sharedEngine()->setEffectsVolume(SFXVolume + value);
		volumeLimit();

		if (bg->getPositionX() == 505.f) popupExtendTime();
	}
}