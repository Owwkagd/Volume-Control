#pragma once
#include <Geode/Geode.hpp>


using namespace geode::prelude;
using namespace keybinds;



class VolumePopup : public CCMenu {
protected:
	bool init(CCScene* p0) {
		// music
		this->template addEventListener<InvokeBindFilter>([=](InvokeBindEvent* event) {
			if (event->isDown()) {
				volumeChange(-0.1, "music");

				int musicVolumeGet = FMODAudioEngine::get()->getBackgroundMusicVolume() * 100;
				if (musicVolumeGet == 79) {
					FMODAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.8);
				}
				else if (musicVolumeGet == 59) {
					FMODAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.6);
				}
				labelUpdate();
			}
			return ListenerResult::Propagate;
			}, "volumeDown"_spr);

		this->template addEventListener<InvokeBindFilter>([=](InvokeBindEvent* event) {
			if (event->isDown()) {
				volumeChange(0.1, "music");
				labelUpdate();
			}
			return ListenerResult::Propagate;
			}, "volumeUp"_spr);

		this->template addEventListener<InvokeBindFilter>([=](InvokeBindEvent* event) {
			if (event->isDown()) {
				volumeChange(-0.01, "music");
				labelUpdate();
			}
			return ListenerResult::Propagate;
			}, "volumeDownBit"_spr);

		this->template addEventListener<InvokeBindFilter>([=](InvokeBindEvent* event) {
			if (event->isDown()) {
				volumeChange(0.01, "music");
				labelUpdate();
			}
			return ListenerResult::Propagate;
			}, "volumeUpBit"_spr);

		// sfx
		this->template addEventListener<InvokeBindFilter>([=](InvokeBindEvent* event) {
			if (event->isDown()) {
				volumeChange(-0.1, "sfx");
				int SFXVolumeGet = FMODAudioEngine::get()->getEffectsVolume() * 100;

				if (SFXVolumeGet == 79) {
					FMODAudioEngine::sharedEngine()->setEffectsVolume(0.8);
				}
				else if (SFXVolumeGet == 59) {
					FMODAudioEngine::sharedEngine()->setEffectsVolume(0.6);
				}
				labelUpdate();
			}
			return ListenerResult::Propagate;
			}, "sfxDown"_spr);

		this->template addEventListener<InvokeBindFilter>([=](InvokeBindEvent* event) {
			if (event->isDown()) {
				volumeChange(0.1, "sfx");
				labelUpdate();
			}
			return ListenerResult::Propagate;
			}, "sfxUp"_spr);

		this->template addEventListener<InvokeBindFilter>([=](InvokeBindEvent* event) {
			if (event->isDown()) {
				volumeChange(-0.01, "sfx");
				labelUpdate();
			}
			return ListenerResult::Propagate;
			}, "sfxDownBit"_spr);

		this->template addEventListener<InvokeBindFilter>([=](InvokeBindEvent* event) {
			if (event->isDown()) {
				volumeChange(0.01, "sfx");
				labelUpdate();
			}
			return ListenerResult::Propagate;
			}, "sfxUpBit"_spr);



		auto winSize = CCDirector::sharedDirector()->getWinSize();

		
		bg = CCSprite::create("GJ_square01-uhd.png");
		bg->setPositionX(640.f);
		bg->setPositionY(32.f);
		bg->setScaleX(1.3);
		bg->setScaleY(0.65);
		bg->setOpacity(127);
		bg->setColor({ (GLubyte)0U, (GLubyte)0U, (GLubyte)0U});

		int musicVolumeGet = FMODAudioEngine::get()->getBackgroundMusicVolume() * 100;
		std::string musicVolumeShow = "Music: " + std::to_string(musicVolumeGet) + "%";

		int SFXVolumeGet = FMODAudioEngine::get()->getEffectsVolume() * 100;
		std::string SFXVolumeShow = "SFX: " + std::to_string(SFXVolumeGet) + "%";

		musicVolumeLabel = CCLabelBMFont::create((musicVolumeShow).c_str(), "bigFont.fnt");
		musicVolumeLabel->setPositionX(640.f);
		musicVolumeLabel->setPositionY(43.f);
		musicVolumeLabel->setScale(0.5);
		
		SFXVolumeLabel = CCLabelBMFont::create((SFXVolumeShow).c_str(), "bigFont.fnt");
		SFXVolumeLabel->setPositionX(640.f);
		SFXVolumeLabel->setPositionY(23.f);
		SFXVolumeLabel->setScale(0.5);


		this->setPosition(0.f, 0.f);
		this->setContentSize(winSize);

		this->addChild(bg);
		this->addChild(musicVolumeLabel);
		this->addChild(SFXVolumeLabel);

		return true;
	}
public:
	CCLabelBMFont* musicVolumeLabel;
	CCLabelBMFont* SFXVolumeLabel;
	CCSprite* bg;

	void labelUpdate();

	void pushPopup();
	void popupExtendTime();

	void volumeLimit();
	void volumeChange(float value, std::string value2);

	static VolumePopup* create(CCScene* p0) {
		auto ret = new VolumePopup();
		if (ret && ret->init(p0)) {
			ret->autorelease();
			return ret;
		}
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
};
