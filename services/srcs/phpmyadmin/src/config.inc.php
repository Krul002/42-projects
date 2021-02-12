<?php
	$cfg['blowfish_secret'] = 'K2058UfC4dLpFD+zMbUY8ds3qfnA/KY7';

	$i=0;
	$i++;
	$cfg['Servers'][$i]['auth_type'] = 'cookie';

	$cfg['Servers'][$i]['host'] = 'mysql-service:3306';
	$cfg['Servers'][$i]['compress'] = false;
	$cfg['Servers'][$i]['AllowNoPassword'] = true;

	$cfg['UploadDir'] = '';
	$cfg['SaveDir'] = '';

	$cfg ['TempDir'] = '/var/www/phpmyadmin/tempdir';
?>