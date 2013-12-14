-- phpMyAdmin SQL Dump
-- version 3.5.8.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Dec 14, 2013 at 10:06 PM
-- Server version: 5.5.34-0ubuntu0.13.04.1
-- PHP Version: 5.4.9-4ubuntu2.4

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `qt_sql`
--

-- --------------------------------------------------------

--
-- Table structure for table `books`
--

CREATE TABLE IF NOT EXISTS `books` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `order_time` datetime DEFAULT NULL,
  `name` varchar(128) DEFAULT NULL,
  `phone` varchar(32) DEFAULT NULL,
  `city` varchar(128) DEFAULT NULL,
  `np_dept` smallint(5) unsigned DEFAULT NULL,
  `order_1` smallint(5) unsigned DEFAULT '0',
  `order_2` smallint(5) unsigned DEFAULT '0',
  `paid` tinyint(1) DEFAULT '0',
  `paid_time` datetime DEFAULT NULL,
  `sent` tinyint(4) DEFAULT '0',
  `sent_time` datetime DEFAULT NULL,
  `remarks` varchar(512) NOT NULL,
  `waybill` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`id`, `order_time`, `name`, `phone`, `city`, `np_dept`, `order_1`, `order_2`, `paid`, `paid_time`, `sent`, `sent_time`, `remarks`, `waybill`) VALUES
(1, '2013-12-06 08:25:29', 'Иванов Иван Иванович', '+38-093-123-45-67', 'Украина, Киев', 13, 14, 88, 1, '2013-12-06 11:31:33', 1, '2013-12-06 16:43:47', 'плохой человек, редиска\nasdasd', '123'),
(2, '2013-12-05 08:29:34', 'Петров Петр Петрович', '+38-093-000-11-22', 'Украина, Харьков', 666, 300, 2000, 0, '2013-12-05 09:34:40', 0, '2013-12-06 16:31:21', 'День первый. Скучно, мерзко, противно. Хочется духовного, возвышенного, чистого. Душа тянется к православию. Надо записаться в хероносцы. Выпил.\nДень второй. Выпил для храбрости. Пошел к хероносцам. По пути выпил еще. К духовному наставнику хероносцев пришел уже храбрым. Он со мной долго говорил, крещен ли? Здоров ли? Блюду ли пост? Не грешу ли? Не заканчивал ли институт? В общем, понравился я ему. Выпили. Плохо помню, как разошлись. Зато хочется блевать и почему то болит жопа. Теперь я хероносец!\nДень тр', '314159265');
