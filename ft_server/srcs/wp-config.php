<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'my_database');

/** MySQL database username */
define('DB_USER', 'admin');

/** MySQL database password */
define('DB_PASSWORD', 'admin');

/** MySQL hostname */
define('DB_HOST', 'localhost');

/** Database Charset to use in creating database tables. */
define('DB_CHARSET', 'utf8');

/** The Database Collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '36aYL]U$#Pr0wW(:`acr>3>3!spu;@rE nIY}rnrr_z$k*C*Qx-I{p+/>L6|?0IX');
define('SECURE_AUTH_KEY',  'aEDG-looggMa!T*qb$X28jOrnH&TF%Kla=$X|{zl?)i=*dKm0C.9<NT&&oXz{.yz');
define('LOGGED_IN_KEY',    '8C!@M|K?uzFr&2?FW|8$`.7`5|jRh%?Gjeib;OJ&%R1z&0zRB{=5Aop&zCnz~l:,');
define('NONCE_KEY',        '8i$.ZO@A(X$ta+A-BSXg_?beXG|6qcc=#GG~YNV#0cq]3QaJ3%xA*u5e_weU|.:Y');
define('AUTH_SALT',        'Cz]-q-SprHLuPo<97(g<U+ %-=:/q?@Qu:?wqtlgO|o%c65b:X=FcO8tN@hhw]bo');
define('SECURE_AUTH_SALT', '8g09)KiE,>p(QP{bAl)Zn!8-I-078)/liLQfOv%_?]8Yb}yd{hg85?j=injRw`c%');
define('LOGGED_IN_SALT',   '^6}tRuUs_Qz_`t?cN|aVA^[~W1@E(;wM]~ m>rIS]FU<%*cA>^l)?T|~=lma=L-q');
define('NONCE_SALT',       'j-UB7;j<?axfhO{?&vWw+I]6%T [S4/#f3!-agA)mfUMEG]EMM!T*3/|t~4-VMO&');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix  = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define('WP_DEBUG', false);

/* That's all, stop editing! Happy blogging. */

/** Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
        define('ABSPATH', dirname(__FILE__) . '/');

/** Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');
?>