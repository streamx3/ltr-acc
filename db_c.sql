CREATE TABLE IF NOT EXISTS `books` (
  `id` int AUTO_INCREMENT,
  `order_time` datetime DEFAULT NULL,
  `name` varchar utf8 DEFAULT NULL,
  `phone` varchar utf8 DEFAULT NULL,
  `city` varchar utf8 DEFAULT NULL,
  `np_dept` smallint DEFAULT NULL,
  `order_1` smallint DEFAULT '0',
  `order_2` smallint DEFAULT '0',
  `paid` tinyint DEFAULT '0',
  `paid_time` datetime DEFAULT NULL,
  `sent` tinyint DEFAULT '0',
  `sent_time` datetime DEFAULT NULL,
  `remarks` varchar utf8 NOT NULL,
  PRIMARY KEY (`id`)
);

