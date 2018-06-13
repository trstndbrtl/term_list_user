<?php

namespace Drupal\term_list_user\Controller;

use Drupal\Core\Controller\ControllerBase;
use Symfony\Component\HttpKernel\Exception\AccessDeniedHttpException;

/**
 * Controller routines for page example routes.
 */
class UserTermPageController extends ControllerBase {

  /**
   * {@inheritdoc}
   */
  protected function getModuleName() {
    return 'term_list_user';
  }

  public function page($iname, $iuid, $itype, $itid, $itname) {
    // Make sure you don't trust the URL to be safe! Always check for exploits.
    // if (!is_numeric($userid) || !is_string($typeArticle) || !is_numeric($typeArticle)) {
    //   // We will just show a standard "access denied" page in this case.
    //   throw new AccessDeniedHttpException();
    // }

    // Construct element and it's data.
    $element = array(
      '#theme' => 'term_user_page',
      '#iname' => $iname,
      '#iuid' => $iuid,
      '#itype' => $itype,
      '#itid' => $itid,
      '#itname' => $itname,
    );
    return $element;
  }

}
