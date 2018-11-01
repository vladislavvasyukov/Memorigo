BEGIN;                                                                                                                --

CREATE TABLE `cards` (
    `id` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    `question` VARCHAR(128) NOT NULL,
    `answer` VARCHAR(128) NOT NULL,
    `created_date` TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    `e_factor` REAL NOT NULL DEFAULT 2.5,
    `last_repetition_date` TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    `next_repetition_date` TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE `decks` (
	`id` integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
	`title` varchar(128) NOT NULL
);

CREATE TABLE `users` (
	`id` integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
	`name` varchar(128) NOT NULL, 
	`login` varchar(128) NOT NULL UNIQUE, 
	`password` varchar(128) NOT NULL, 
	`registration_date` TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

ALTER TABLE `decks` RENAME TO `decks__old`;

CREATE TABLE `decks` (
	`id` integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
	`title` varchar(128) NOT NULL, 
	`user_id` integer NOT NULL REFERENCES `users` (`id`)
);

INSERT INTO `decks` (`id`, `title`, `user_id`) 
	SELECT 
		`id`, `title`, NULL 
	FROM 
		`decks__old`;

DROP TABLE `decks__old`;

CREATE INDEX `decks_user_id_3fa0056d` ON `decks` (`user_id`);

ALTER TABLE `cards` RENAME TO `cards__old`;

CREATE TABLE `cards` (
	`id` integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
	`question` varchar(128) NOT NULL, 
	`answer` varchar(128) NOT NULL, 
	`created_date` TIMESTAMP DEFAULT CURRENT_TIMESTAMP, 
	`e_factor` real NOT NULL DEFAULT 2.5, 
	`last_repetition_date` TIMESTAMP DEFAULT CURRENT_TIMESTAMP, 
	`next_repetition_date` TIMESTAMP DEFAULT CURRENT_TIMESTAMP, 
	`deck_id` integer NOT NULL REFERENCES `decks` (`id`)
);

INSERT INTO `cards` (`id`, `question`, `answer`, `created_date`, `e_factor`, `last_repetition_date`, `next_repetition_date`, `deck_id`) 
	SELECT 
		`id`, `question`, `answer`, `created_date`, `e_factor`, `last_repetition_date`, `next_repetition_date`, NULL 
	FROM 
		`cards__old`;

CREATE INDEX `cards_deck_id_5686f3c5` ON `cards` (`deck_id`);
COMMIT;
