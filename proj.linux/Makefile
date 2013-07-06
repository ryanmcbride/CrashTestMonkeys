EXECUTABLE = CrashTestMonkeys

INCLUDES = -I.. \
           -I../Classes \
           -I../libs/CocosDenshion/include \
           -I../libs/external/Box2D \
	   -I../libs/external/chipmunk/include/chipmunk \
	   -I../libs/external \
           -I../libs/extensions \
	   -I../libs/extensions/LocalStorage

SOURCES = main.cpp \
        ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/ScreenHelper.cpp \
                   ../../Classes/AudioManager.cpp \
                   ../../Classes/GLES-Render.cpp \
                   ../../Classes/Commercials/BoredRoom.cpp \
                   ../../Classes/Commercials/CarCrash.cpp \
                   ../../Classes/Commercials/CNN.cpp \
                   ../../Classes/Commercials/Commercial.cpp \
                   ../../Classes/Commercials/KenHint.cpp \
                   ../../Classes/Commercials/McAcme.cpp \
                   ../../Classes/Level/Backgrounds/BackGround.cpp \
                   ../../Classes/Level/Backgrounds/TutorialBackGround.cpp \
                   ../../Classes/Level/Backgrounds/CityBackGround.cpp \
                   ../../Classes/Level/Backgrounds/NightBackGround.cpp \
                   ../../Classes/Level/Backgrounds/SpaceBackGround.cpp \
                   ../../Classes/Level/Backgrounds/TikiBackGround.cpp \
                   ../../Classes/Level/Rider/Fire.cpp \
                   ../../Classes/Level/Rider/AnimationSet.cpp \
                   ../../Classes/Level/Rider/BikeAudio.cpp \
                   ../../Classes/Level/Rider/Biped.cpp \
                   ../../Classes/Level/Rider/BipedDef.cpp \
                   ../../Classes/Level/Rider/DirtBike.cpp \
                   ../../Classes/Level/Rider/Monkey.cpp \
                   ../../Classes/Level/Rider/DummyRider.cpp \
                   ../../Classes/Level/Rider/Vehicle.cpp \
                   ../../Classes/Level/Rider/Rider.cpp \
                   ../../Classes/Level/Objects/TutorialManager1.cpp \
                   ../../Classes/Level/Objects/TutorialManager2.cpp \
                   ../../Classes/Level/Objects/TutorialManager3.cpp \
                   ../../Classes/Level/Objects/TutorialManager4.cpp \
                   ../../Classes/Level/Objects/TutorialManager5.cpp \
                   ../../Classes/Level/Objects/TutorialManager6.cpp \
                   ../../Classes/Level/Objects/TutorialManager7.cpp \
                   ../../Classes/Level/Objects/TutorialManager8.cpp \
                   ../../Classes/Level/Objects/WaterTank.cpp \
                   ../../Classes/Level/Objects/Spline.cpp \
                   ../../Classes/Level/Objects/SingleLoop.cpp \
                   ../../Classes/Level/Objects/DoubleLoop.cpp \
                   ../../Classes/Level/Objects/TripleLoop.cpp \
                   ../../Classes/Level/Objects/Pickup.cpp \
                   ../../Classes/Level/Objects/ManHole.cpp \
                   ../../Classes/Level/Objects/Swing.cpp \
                   ../../Classes/Level/Objects/SpaceOrb.cpp \
                   ../../Classes/Level/Objects/Kittens.cpp \
                   ../../Classes/Level/Objects/ExplodingBarrel.cpp \
                   ../../Classes/Level/Objects/Crate.cpp \
                   ../../Classes/Level/Objects/RotatingAirBoost.cpp \
                   ../../Classes/Level/Objects/Bridge.cpp \
                   ../../Classes/Level/Objects/Barrier.cpp \
                   ../../Classes/Level/Objects/AirBoost.cpp \
                   ../../Classes/Level/Objects/Porcupine.cpp \
                   ../../Classes/Level/Objects/Trampoline.cpp \
                   ../../Classes/Level/Objects/FinishLine.cpp \
                   ../../Classes/Level/Objects/SpawnPoint.cpp \
                   ../../Classes/Level/Objects/Platform.cpp \
                   ../../Classes/Level/Objects/TurboStrip.cpp \
                   ../../Classes/Level/Objects/Ramp.cpp \
                   ../../Classes/Level/Objects/TextureObject.cpp \
                   ../../Classes/Level/Objects/TrackObject.cpp \
                   ../../Classes/Level/Objects/Trigger.cpp \
                   ../../Classes/Level/FinishOverlay.cpp \
                   ../../Classes/Level/CrashOverlay.cpp \
                   ../../Classes/Level/Level.cpp \
                   ../../Classes/Level/LevelContactListener.cpp \
		   ../../Classes/Level/Track.cpp \
                   ../../Classes/Level/HUD.cpp \
                   ../../Classes/Level/ScoreManager.cpp \
                   ../../Classes/FrontEnd/Store/Store.cpp \
                   ../../Classes/FrontEnd/Store/GetPeanuts.cpp \
                   ../../Classes/FrontEnd/XMLLevelLoader.cpp \
                   ../../Classes/FrontEnd/SaveLoad.cpp \
                   ../../Classes/FrontEnd/CCScrollingMenu.cpp \
                   ../../Classes/FrontEnd/FirstPlay.cpp \
                   ../../Classes/FrontEnd/MainMenu.cpp \
                   ../../Classes/FrontEnd/Options.cpp \
                   ../../Classes/FrontEnd/Achievements.cpp \
                   ../../Classes/FrontEnd/FirstLoad.cpp \
                   ../../Classes/FrontEnd/Credits.cpp \
                   ../../Classes/FrontEnd/LevelSelect.cpp \
                   ../../Classes/FrontEnd/Loading.cpp \
                   ../../Classes/FrontEnd/MoreGames.cpp \
                   ../../Classes/FrontEnd/Pause.cpp \
                   ../../Classes/FrontEnd/QuestionMark.cpp \
                   ../../Classes/FrontEnd/RegionSelect.cpp \
                   ../../Classes/FrontEnd/Feedback.cpp \
		   ../../libs/extensions/LocalStorage/LocalStorage.cpp

COCOS_ROOT = ../libs
include $(COCOS_ROOT)/cocos2dx/proj.linux/cocos2dx.mk

SHAREDLIBS += -lcocos2d -lbox2d -lcocosdenshion -lextension -lsqlite3
COCOS_LIBS = $(LIB_DIR)/libcocos2d.so

$(TARGET): $(OBJECTS) $(STATICLIBS) $(COCOS_LIBS) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_LINK)$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

$(OBJ_DIR)/%.o: %.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@
