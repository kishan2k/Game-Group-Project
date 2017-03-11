CREATE TABLE `Player` (
	`PlayerID` INT(32) NOT NULL,
	`Name` TEXT(10) NOT NULL,
	`Health` INT(16) NOT NULL,
	`Strength` INT(16) NOT NULL,
	`CurrentScore` INT(32) NOT NULL,
	`Level` INT(8) NOT NULL,
	`EnergyLevel` INT(16) NOT NULL,
	PRIMARY KEY (`PlayerID`)
);

CREATE TABLE `High_Score` (
	`HighScoreID` INT(32) NOT NULL,
	`Date/Time` DATETIME NOT NULL,
	`PlayerID` INT(32) NOT NULL,
	`HighScore` INT(32) NOT NULL,
	`LevelReached` INT(32) NOT NULL,
	PRIMARY KEY (`HighScoreID`)
);

CREATE TABLE `Levels` (
	`LevelsID` INT(8) NOT NULL,
	`LevelNumber` INT(8) NOT NULL,
	`Map` VARCHAR(1024) NOT NULL,
	PRIMARY KEY (`LevelsID`)
);

CREATE TABLE `Loot` (
	`LootID` INT(8) NOT NULL,
	`TypeOfItem` varchar(32) NOT NULL,
	`Item` varchar(32) NOT NULL,
	`Effect` varchar(32) NOT NULL,
	`Duration` INT(8) NOT NULL,
	`Amount` INT(16) NOT NULL,
	PRIMARY KEY (`LootID`)
);

CREATE TABLE `Enemy` (
	`EnemyID` INT(16) NOT NULL,
	`Strength` INT(16) NOT NULL,
	`Health` INT(16) NOT NULL,
	`LootID` INT(8) NOT NULL,
	`EnergyLevel` INT(16) NOT NULL,
	PRIMARY KEY (`EnemyID`)
);

CREATE TABLE `Save_Games` (
	`SaveGamesID` INT(16) NOT NULL,
	`PlayerID` INT(32) NOT NULL,
	`CurrentMap` VARCHAR(64) NOT NULL,
	PRIMARY KEY (`SaveGamesID`)
);

CREATE TABLE `Levels_Enemy` (
	`LevelEnemyID` INT(8) NOT NULL,
	`LevelsID` INT(8) NOT NULL,
	`EnemyID` INT(8) NOT NULL,
	PRIMARY KEY (`LevelEnemyID`)
);

ALTER TABLE `Player` ADD CONSTRAINT `Player_fk0` FOREIGN KEY (`Level`) REFERENCES `Levels`(`LevelsID`);

ALTER TABLE `High_Score` ADD CONSTRAINT `High_Score_fk0` FOREIGN KEY (`PlayerID`) REFERENCES `Player`(`PlayerID`);

ALTER TABLE `Enemy` ADD CONSTRAINT `Enemy_fk0` FOREIGN KEY (`LootID`) REFERENCES `Loot`(`LootID`);

ALTER TABLE `Save_Games` ADD CONSTRAINT `Save_Games_fk0` FOREIGN KEY (`PlayerID`) REFERENCES `Player`(`PlayerID`);

ALTER TABLE `Levels_Enemy` ADD CONSTRAINT `Levels_Enemy_fk0` FOREIGN KEY (`LevelsID`) REFERENCES `Levels`(`LevelsID`);

ALTER TABLE `Levels_Enemy` ADD CONSTRAINT `Levels_Enemy_fk1` FOREIGN KEY (`EnemyID`) REFERENCES `Enemy`(`EnemyID`);

