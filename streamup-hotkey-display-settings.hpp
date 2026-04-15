#pragma once

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QGroupBox>
#include <obs-frontend-api.h>
#include "streamup-hotkey-display-dock.hpp"
#include "streamup-ui.hpp"

class StreamupHotkeyDisplaySettings : public QDialog {
	Q_OBJECT

public:
	StreamupHotkeyDisplaySettings(HotkeyDisplayDock *dock, QWidget *parent);
	void LoadSettings(obs_data_t *settings);
	void SaveSettings();

	void PopulateSceneComboBox();
	void PopulateSourceComboBox(const QString &sceneName);

	QString sceneName;
	QString textSource;
	int onScreenTime;
	bool displayInTextSource;

	// Single key capture settings
	bool captureNumpad;
	bool captureNumbers;
	bool captureLetters;
	bool capturePunctuation;
	bool captureStandaloneMouse;
	QString whitelistedKeys;

	// Logging settings
	bool enableLogging;

private:
	HotkeyDisplayDock *hotkeyDisplayDock;
	QVBoxLayout *mainLayout;
	QHBoxLayout *buttonLayout;
	QHBoxLayout *sceneLayout;
	QHBoxLayout *sourceLayout;
	QHBoxLayout *prefixLayout;
	QHBoxLayout *suffixLayout;
	QLabel *sceneLabel;
	QLabel *sourceLabel;
	QLabel *timeLabel;
	QLabel *prefixLabel;
	QLabel *suffixLabel;
	QLineEdit *prefixLineEdit;
	QLineEdit *suffixLineEdit;
	QComboBox *sceneComboBox;
	QComboBox *sourceComboBox;
	QComboBox *browserSourceComboBox;
	QSpinBox *timeSpinBox;
	SwitchWidget *displayInTextSourceCheckBox;
	SwitchWidget *displayInBrowserSourceCheckBox;
	QGroupBox *textSourceGroupBox;
	QGroupBox *browserSourceGroupBox;
	QGroupBox *singleKeyGroupBox;
	QGroupBox *displayGroupBox;
	QGroupBox *toggleGroupBox;

	// New toggle controls
	SwitchWidget *sendKeyboardCheckBox;
	SwitchWidget *sendClicksCheckBox;
	SwitchWidget *sendScrollCheckBox;
	SwitchWidget *sendPositionCheckBox;

	// Single key capture UI elements
	SwitchWidget *captureNumpadCheckBox;
	SwitchWidget *captureNumbersCheckBox;
	SwitchWidget *captureLettersCheckBox;
	SwitchWidget *capturePunctuationCheckBox;
	SwitchWidget *captureStandaloneMouseCheckBox;
	QLabel *whitelistLabel;
	QPlainTextEdit *whitelistTextEdit;

	// Display settings group
	QGroupBox *displayGroupBox;

	// Display format UI elements
	QLabel *separatorLabel;
	QLineEdit *separatorLineEdit;
	QLabel *maxHistoryLabel;
	QSpinBox *maxHistorySpinBox;

	// Logging UI elements
	SwitchWidget *enableLoggingCheckBox;

private slots:
	void applySettings();
	void onSceneChanged(const QString &sceneName);
	void onDisplayInTextSourceToggled(bool checked);
};
